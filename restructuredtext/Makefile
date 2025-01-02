URL1=https://hjlebbink.github.io/x86doc/
URL2=https://www.felixcloutier.com/x86/

x86doc.py: x86doc1.html x86doc2.html mkx86doc.py
	python3 mkx86doc.py $(URL1) x86doc1.html $(URL2) x86doc2.html $@

x86doc1.html:
	curl $(URL1) -o $@

x86doc2.html:
	curl $(URL2) -o $@
