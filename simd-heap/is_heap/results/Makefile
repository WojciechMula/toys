RST=ryzen7.rst icelake.rst

%.rst: %.txt
	python3 format.py $< > /dev/shm/$@
	mv /dev/shm/$@ $@

.PHONY: all
all: $(RST)

.PHONY: clear
clear:
	$(RM) $(RST)
