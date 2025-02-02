#!/usr/bin/env python3
import subprocess


def main():
    model = get_cpu_model()
    gcc   = get_gcc_version()

    print(f"CPU: {model}")
    print(f"GCC: {gcc}")


def get_cpu_model():
    with open('/proc/cpuinfo', 'r') as f:
        for line in f:
            if line.startswith('model name'):
                # model name  : string
                return line.partition(':')[2].strip()


def get_gcc_version():
    cmd   = ["gcc", "--version"]
    out   = subprocess.Popen(cmd, stdout=subprocess.PIPE).communicate()[0].decode("utf-8")
    lines = [line for line in map(strip, out.splitlines()) if line]

    if lines:
        return lines[0].strip()


def strip(s):
    return s.strip()


if __name__ == '__main__':
    main()
