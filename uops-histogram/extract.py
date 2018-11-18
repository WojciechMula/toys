import xml.etree.ElementTree as ET
import sys

def main():
    path = sys.argv[1]
    arch = sys.argv[2]

    data = ET.parse(path)
    for instruction in data.getiterator('instruction'):
        uops = instruction.find("./architecture[@name='%s']/IACA[@version='3.0']" % arch)
        if uops is not None:
            instr = instruction.attrib['asm']
            isa   = instruction.attrib['isa-set']
            print isa, uops.attrib['total_uops'], instr


if __name__ == '__main__':
    main()
