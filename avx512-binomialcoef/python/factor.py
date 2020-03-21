def factor(x):
    assert x > 0
    k = 2

    result = []
    while x > 1:
        if (x % k) == 0:
            result.append(k)
            x //= k
        else:
            if k == 2:
                k = 3
            else:
                k += 2

    return tuple(result)               


class Primes:
    def __init__(self, primes):
        self.index = {}
        self.prime = {}

        for index, prime in enumerate(primes):
            self.index[prime] = index
            self.prime[index] = prime


    def __len__(self):
        return len(self.prime)


class FactorialNumber:
    def __init__(self, factors, primes):
        self.primes = primes
        self.powers = [0] * len(primes)
        for factor in factors:
            index = self.primes.index[factor]
            self.powers[index] += 1


    def __str__(self):
        tmp = []
        for index, power in enumerate(self.powers):
            if power > 0:
                prime = self.primes.prime[index]
                if power > 1:
                    tmp.append(f"{prime}^{power}")
                else:
                    tmp.append(f"{prime}")

        val = self.val()
        tmp = ' * '.join(tmp)
        return f"{val} = {tmp}"


    def __iadd__(self, x):
        assert type(x) is type(self)
        assert x.primes is self.primes

        for index, power in enumerate(x.powers):
            self.powers[index] += power

        return self


    def __isub__(self, x):
        assert type(x) is type(self)
        assert x.primes is self.primes

        for index, power in enumerate(x.powers):
            self.powers[index] += power

        return self


    def __iter__(self):
        for index, power in enumerate(self.powers):
            yield (self.primes.prime[index], power)


    def val(self):
        res = 1
        for index, power in enumerate(self.powers):
            if power > 0:
                prime = self.primes.prime[index]
                res *= prime**power
        
        return res


def precalculate(primes_count = 64):
    x = 2
    primes = []
    factored = []
    while len(primes) < primes_count:
        f = factor(x)
        if len(f) == 1:
            primes.append(x)

        factored.append(f)
        x += 1

    primes = Primes(primes)
    yield FactorialNumber([], primes)
    for factors in factored:
        yield FactorialNumber(factors, primes)


def main():
    numbers = list(precalculate())
    primes = numbers[0].primes


if __name__ == '__main__':
    main()
