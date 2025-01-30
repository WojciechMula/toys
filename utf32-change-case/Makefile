FLAGS=-Wall -Wextra -pedantic -O3 -march=native -std=c++17 -ggdb # -Werror

ALL=verify \
    benchmark

DEPS=application_base.cpp \
     impl.cpp \
     scalar.cpp \
     avx2.cpp \
     plain.cpp.inl \
     compressed_v1.cpp.inl \
     compressed_v2.cpp.inl \
     compressed_v3.cpp.inl \
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

plain.cpp.inl: scripts/plain_lookup.py
	python3 scripts/plain_lookup.py > $(TMP)/$@
	mv $(TMP)/$@ $@

compressed_v1.cpp.inl: scripts/compressed_lookup_v1.py
	python3 scripts/compressed_lookup_v1.py > $(TMP)/$@
	mv $(TMP)/$@ $@

compressed_v2.cpp.inl: scripts/compressed_lookup_v2.py
	python3 scripts/compressed_lookup_v2.py > $(TMP)/$@
	mv $(TMP)/$@ $@

compressed_v3.cpp.inl: scripts/compressed_lookup_v3.py
	python3 scripts/compressed_lookup_v3.py $(TMP)/$@
	mv $(TMP)/$@ $@

aux_conv.cpp.inl: scripts/aux_conv_cpp.py
	python3 scripts/aux_conv_cpp.py $(TMP)/$@
	mv $(TMP)/$@ $@

compressed_avx2.cpp.inl: scripts/compressed_lookup_avx2.py
	python3 scripts/compressed_lookup_avx2.py > $(TMP)/$@
	mv $(TMP)/$@ $@

cpp_lookup.cpp.inl: scripts/cpp_lookup.py
	python3 scripts/cpp_lookup.py > $(TMP)/$@
	mv $(TMP)/$@ $@
