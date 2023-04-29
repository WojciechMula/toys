def main():
    path = 'go.txt'
    n = 5

    words = load_words(path, n)
    size = len(words[0])
    lookup = list(range(size))
    def transform(word):
        tmp = ''
        for idx in lookup:
            if idx >= 0:
                tmp += word[idx]

        return tmp

    s = {transform(word) for word in words}
    assert len(s) == len(words)
    
    for i in range(size):
        if words[0][i] == '.':
            continue
        lookup[i] = -1
        s = {transform(word) for word in words}
        if len(s) != len(words):
            # not unique, revert
            lookup[i] = i

    for word in words:
        print('%s => ' % word, end='')
        for idx in lookup:
            if idx >= 0:
                print(word[idx], end='')
            else:
                print('_', end='')
        print()


def load_words(path, n):
    result = []
    with open('go.txt') as f:
        for line in f:
            line = line.rstrip()
            if len(line) != n:
                continue

            tmp = ''
            for c in line:
                tmp += '.{0:08b}'.format(ord(c))

            tmp = tmp[1:]
            result.append(tmp)
    
    return result

if __name__ == '__main__':
    main()
