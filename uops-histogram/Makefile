ARCH=SKX # SkylakeX
ISA=AVX AVX2 AVX2GATHER AVX512BW_128 AVX512BW_128N AVX512BW_256 AVX512BW_512 AVX512BW_KOP AVX512CD_128 AVX512CD_256 AVX512CD_512 AVX512DQ_128 AVX512DQ_128N AVX512DQ_256 AVX512DQ_512 AVX512DQ_KOP AVX512DQ_SCALAR AVX512F_128 AVX512F_128N AVX512F_256 AVX512F_512 AVX512F_KOP AVX512F_SCALAR AVXAES FMA PCLMULQDQ SSE SSE2 SSE2MMX SSE3 SSE3X87 SSE4 SSE42 SSEMXCSR SSE_PREFETCH SSSE3 SSSE3MMX

histogram.txt: uops.txt histogram.py
	python histogram.py $(ISA) < $< > tmp.txt
	mv tmp.txt $@

uops.txt: instructions.xml extract.py
	python extract.py $< $(ARCH) > tmp.txt
	mv tmp.txt $@

dumpisa: uops.txt
	awk '{print $$1}' < $< | sort -u

instructions.xml:
	wget http://uops.info/instructions.xml

clean:
	$(RM) uops.txt
