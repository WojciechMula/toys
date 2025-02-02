RST=icelake.rst ryzen7.rst

%.rst: %.txt
	python3 format.py $< > /dev/shm/$@
	mv /dev/shm/$@ $@

.PHONY: ALL
ALL: $(RST)
