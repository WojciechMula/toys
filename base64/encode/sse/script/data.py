from collections import OrderedDict

class Data:
    def __init__(self, file):

        self.reject = set(['scalar (32 bit)'])
        self.data = self.__load(file)


    def __iter__(self):
        return self.data.iteritems()


    def __load(self, file):

        result = OrderedDict()

        for line in file:

            try:
                name, tail = line.split("...", 2)
            except ValueError:
                continue

            name = name.strip()
            if name in self.reject:
                continue

            time = float(tail.split()[0])
            result[name] = min(time, result.get(name, time))

        return result
