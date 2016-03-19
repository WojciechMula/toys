from collections import OrderedDict

class Data:
    def __init__(self, file):

        self.data = self.__load(file)


    def __iter__(self):
        return self.data.iteritems()


    def __load(self, file):

        result = OrderedDict()

        for line in file:

            fields = [f.strip() for f in line.split(',')]

            name, lookup, pack, time = fields

            time = float(time)
            key  = (name, lookup, pack)
            result[key] = min(time, result.get(key, time))

        return result
