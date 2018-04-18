import sys
import subprocess

class Runner(object):
    def __init__(self, executable, size, iterations):
        self.executable = executable
        self.size = size
        self.iterations = iterations


    def run(self):
        args = self.__prepare_arguments()
        proc = subprocess.Popen(args, stdout=subprocess.PIPE)
        res  = proc.communicate()[0]
        ret  = proc.wait()
        if ret != 0:
            print args
            print res
            raise RuntimeError("program failed")

        return res.rstrip()


    def __prepare_arguments(self):
        return (
            self.executable,
            '%d'    % self.size,
            '%d'    % self.iterations,
            '--csv'
        )


parameters = [
    (128,       100000),
    (256,       100000),
    (512,       100000),
    (1024,      100000),
    (2048,      100000),
    (4096,      100000),
    (16384,     100000),
    (65536,     100000),
]


def main(executable):
    for size, iterations in parameters:
        r = Runner(executable, size, iterations)
        print r.run()

if __name__ == '__main__':
    main(sys.argv[1])
