all: compressed_v3.rst compressed_v4.rst statistics.rst

compressed_v3.rst: compressed_v3.py
	python3 compressed_v3.py $@
	touch $@

compressed_v4.rst: compressed_v4.py
	python3 compressed_v4.py $@
	touch $@

statistics.rst: statistics.py
	python3 statistics.py $@
	touch $@
