RST=ryzen7-pdep.rst ryzen7-pext.rst alderlake-pdep.rst alderlake-pext.rst icelake-pdep.rst icelake-pext.rst skylake-x-pdep.rst skylake-x-pext.rst

%.rst: %.txt
	python3 format.py $< > /dev/shm/$@
	mv /dev/shm/$@ $@

.PHONY: all
all: $(RST)

.PHONY: clear
clear:
	$(RM) $(RST)
