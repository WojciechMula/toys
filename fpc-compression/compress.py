import sys
import heapq
import uvint
from pathlib import Path
from status import Status


def main():
    path = Path(sys.argv[1])
    out  = Path(sys.argv[2])
    bytes = path.read_bytes()
    min_length = 4
    max_length = 10

    compressor = Compressor(bytes, min_length, max_length)
    with open(out, 'wb') as f:
        data = compressor.compress_to_file(f)


class Compressor:
    def __init__(self, input, min_length, max_length):
        self.input = input
        self.image = Image(len(input))
        self.min_length = min_length
        self.max_length = max_length

    def compress_to_file(self, file):
        self.histogram = self.__build_histogram()
        symbols = []

        status = Status()
        total  = len(self.histogram)
        while True:
            proc = 100 * (total - len(self.histogram)) / total
            status(f"Compressing {proc:.2f}%")
            best = self.get_best()
            if best is None:
                break

            n = len(best.word)
            symbol = len(symbols)
            image = self.image
            for idx in best.indices:
                if image.is_free(idx, n):
                    self.image.put_symbol(symbol, idx, n)

            image.version += 1
            symbols.append(best.word)

        status.clear()
        commands = self.__input_for_encoding()
        
        #self.__check(symbols, commands)
        self.__compress(file, symbols, commands)

    def __input_for_encoding(self):
        result = []
        raw = b''
        for c, status in zip(self.input, self.image.img):
            if status is used:
                continue

            if status is free:
                raw += c.to_bytes(1, "little")
            else:
                if raw:
                    result.append(raw)
                    raw = b''

                result.append(status) # a symbol

        if raw:
            result.append(raw)

        return result

    def __compress(self, file, symbols, commands):
        # 1a. compress symbols
        for symbol in symbols:
            file.write(uvint.encode(len(symbol)))
            file.write(symbol)

        # 1b. mark the last entry with length 0
        file.write(uvint.encode(0))

        # 2. compress either 1) raw substrings or 2) symbol references
        for item in commands:
            if type(item) is bytes:
                # raw string is encoded as k=[0..127] + k*byte
                while item:
                    k = min(len(item), 127)
                    file.write(uvint.encode(k))
                    file.write(item[:k])
                    item = item[k:]
            else:
                # symbol is encoded as 128 + symbol
                file.write(uvint.encode(item + 128))

    def __check(self, symbols, commands):
        tmp = b''
        for item in commands:
            if type(item) is bytes:
                tmp += item
            else:
                tmp += symbols[item]

        assert tmp == self.input

    def get_best(self):
        histogram = self.histogram
        while len(histogram) > 0:
            best = heapq.heappop(histogram)
            if not self.update_needed(best):
                return best

            self.update_word(best)
            if len(best.indices) > 1:
                heapq.heappush(histogram, best)

        return None


    def update_needed(self, word):
        if word.version == self.image.version:
            return False

        length = len(word.word)
        for idx in word.indices:
            if not self.image.is_free(idx, length):
                return True

        return False


    def update_word(self, word):
        length = len(word.word)
        word.indices = [idx for idx in word.indices if self.image.is_free(idx, length)]
        word.version = self.image.version


    def __build_histogram(self):
        freq  = {}
        input = self.input
        n     = len(input)

        status = Status()
        for i in range(0, n):
            status("Building histogram %d/%d (%0.2f%%)" % (i, n, 100 * i / n))
            for length in range(self.min_length, self.max_length + 1):
                substr = input[i:i+length]
                if len(substr) != length:
                    break

                if substr not in freq:
                    freq[substr] = []

                freq[substr].append(i)

        histogram = [Word(word, indices) for word, indices in freq.items() if len(indices) > 1]
        histogram.sort()

        status.clear()
        return histogram


free = None
used = object()

class Image:
    """
    Image tell which bytes in input was already replaced.
    """
    def __init__(self, length):
        self.img = [free] * length
        self.version = 0

    def is_free(self, idx, length):
        """
        Checks if all bytes in range [idx:idx+length] are free.
        """
        for i in range(idx, idx + length):
            if self.img[i] is not free:
                return False

        return True

    def put_symbol(self, symbol, idx, length):
        """
        Marks range [idx:idx+length] as reserved.
        The first item in the range keeps the symbol.
        """
        for i in range(idx, idx + length):
            self.img[i] = used

        self.img[idx] = symbol


class Word:
    def __init__(self, word, indices):
        self.word = word
        self.indices = indices
        self.version = 0

    @property
    def weight(self):
        """
        How profitable is to replace this word
        """
        return len(self.indices) * len(self.word)

    def __repr__(self):
        return '<%s: %d [weight=%d]>' % (self.word, len(self.indices), self.weight)

    def __lt__(self, other):
        return self.weight > other.weight


if __name__ == '__main__':
    main()
