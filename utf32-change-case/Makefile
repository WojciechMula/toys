FLAGS_COMMON=-Wall -Wextra -pedantic -O3 -std=c++17 -ggdb # -Werror
FLAGS=$(FLAGS_COMMON) -march=native
FLAGS_AVX512=$(FLAGS_COMMON) -D HAVE_AVX512 -march=icelake-server # -march=native

ALL=verify \
    benchmark \
    verify_avx512 \
    benchmark_avx512

DEPS=application_base.cpp \
     impl.cpp \
     scalar.cpp \
     avx2.cpp \
     plain.cpp.inl \
     compressed_v1.cpp.inl \
     compressed_v2.cpp.inl \
     compressed_v3.cpp.inl \
     compressed_v4.cpp.inl \
     compressed_v5.cpp.inl \
     compressed_v6.cpp.inl \
     compressed_avx2.cpp.inl \
     aux_conv.cpp.inl \
     cpp_lookup.cpp.inl

TMP=/dev/shm

.PHONY: all
all: $(ALL)

.PHONY: clean
clean:
	$(RM) $(ALL)

verify: $(DEPS) verify.cpp
	$(CXX) $(FLAGS) verify.cpp -o $@

benchmark: $(DEPS) benchmark.cpp
	$(CXX) $(FLAGS) benchmark.cpp -o $@

verify_avx512: $(DEPS) verify.cpp
	$(CXX) $(FLAGS_AVX512) verify.cpp -o $@

benchmark_avx512: $(DEPS) benchmark.cpp
	$(CXX) $(FLAGS_AVX512) benchmark.cpp -o $@

plain.cpp.inl: scripts/plain_lookup.py
	python3 scripts/plain_lookup.py $(TMP)/$@
	mv $(TMP)/$@ $@

compressed_v1.cpp.inl: scripts/compressed_lookup_v1.py
	python3 scripts/compressed_lookup_v1.py $(TMP)/$@
	mv $(TMP)/$@ $@

compressed_v2.cpp.inl: scripts/compressed_lookup_v2.py
	python3 scripts/compressed_lookup_v2.py $(TMP)/$@
	mv $(TMP)/$@ $@

compressed_v3.cpp.inl: scripts/compressed_lookup_v3.py
	python3 scripts/compressed_lookup_v3.py $(TMP)/$@ V3 4 trim
	mv $(TMP)/$@ $@

compressed_v4.cpp.inl: scripts/compressed_lookup_v3.py
	python3 scripts/compressed_lookup_v3.py $(TMP)/$@ V4 12 no-trim
	mv $(TMP)/$@ $@

compressed_v5.cpp.inl: scripts/compressed_lookup_v3.py
	python3 scripts/compressed_lookup_v3.py $(TMP)/$@ V5 11 no-trim
	mv $(TMP)/$@ $@

compressed_v6.cpp.inl: scripts/compressed_lookup_v3.py
	python3 scripts/compressed_lookup_v3.py $(TMP)/$@ V6 10 no-trim
	mv $(TMP)/$@ $@

aux_conv.cpp.inl: scripts/aux_conv_cpp.py
	python3 scripts/aux_conv_cpp.py $(TMP)/$@
	mv $(TMP)/$@ $@

compressed_avx2.cpp.inl: scripts/compressed_lookup_avx2.py
	python3 scripts/compressed_lookup_avx2.py $(TMP)/$@
	mv $(TMP)/$@ $@

cpp_lookup.cpp.inl: scripts/cpp_lookup.py
	python3 scripts/cpp_lookup.py $(TMP)/$@
	mv $(TMP)/$@ $@
