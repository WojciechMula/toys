from os.path import basename

def load(file):
    data = {}
    for line in file:
        F = line.split(':')

        if len(F) == 1:
            file = basename(F[0].strip())
            if file not in data:
                data[file] = []
            continue

        assert file is not None
        name = F[0].strip()
        F = F[1].split()

        
        time = int(F[1])
        data[file].append((name, time))

    return data
