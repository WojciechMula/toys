import errno
import platform
import subprocess


class Base:
    def __init__(self):
        self.flags = set()

        try:
            tmp = self.get_flags() or []
            self.flags = set(tmp)
        except IOError as e:
            if e.errno == errno.ENOENT:
                return

            raise


    def __contains__(self, name):
        return name in self.flags


class Linux(Base):
    def get_flags(self):
        with open('/proc/cpuinfo', 'r') as f:
            for line in f:
                if line.startswith('flags'):
                    return line.split()[2:]


class ARM(Base):
    def get_flags(self):
        with open('/proc/cpuinfo', 'r') as f:
            for line in f:
                if line.startswith('Features'):
                    return line.split()[2:]


class MacOS(Base):
    def get_flags(self):
        return subprocess.Popen("sysctl -n machdep.cpu ".split(),  stdout=subprocess.PIPE).communicate()[0].decode("utf-8").lower().split()



if platform.system() == 'Darwin':
    CPUFlags = MacOS
else:
    if platform.machine().startswith('arm'):
        CPUFlags = ARM
    else:
        CPUFlags = Linux

def main():

    import sys

    flags = CPUFlags()

    if len(sys.argv) == 2:
        if sys.argv[1] in flags:
            print ("present")


if __name__ == '__main__':
    main()
