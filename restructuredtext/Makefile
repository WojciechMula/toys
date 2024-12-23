URL=https://hjlebbink.github.io/x86doc/

x86doc.py: x86doc.html mkx86doc.py
	python3 mkx86doc.py $(URL) $^ $@

x86doc.html:
	curl $(URL) -o $@

