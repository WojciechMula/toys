class Record(object):
    pass


def load_raw(path):
    result = []
    with open(path, 'rt') as f:
        for line in f:
            F = map(int, line.split())
            r = Record()
            r.memory_usage_limit = F[0]
            r.min_alloc = F[1]
            r.max_alloc = F[2]
            r.sum_allocated = F[3]
            r.malloc_calls = F[4]
            r.malloc_allocated = F[5]
            r.malloc_free = F[6]
            r.malloc_waste = r.malloc_allocated - (r.malloc_free + r.sum_allocated)
            r.malloc_waste_perc = 100.0 * r.malloc_waste / r.malloc_allocated
            result.append(r)

    return result


def group(data):
    result = {}
    for record in data:
        key = record.memory_usage_limit
        if key not in result:
            result[key] = []

        result[key].append(record)

    return result


def load(path):
    return group(load_raw(path))
