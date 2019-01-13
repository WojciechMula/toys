from os.path import basename
from procedure_names import display_name

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
        name = display_name[F[0].strip()]
        if name is None:
            continue

        F = F[1].split()

        time = int(F[1])
        data[file].append((name, time))

    return data
