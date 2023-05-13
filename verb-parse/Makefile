FLAGS=-Wall -Wextra -std=c++17 -O3 -march=native

run: benchmark
	./benchmark 100 10000
	./benchmark 1000 1000
	./benchmark 10000 100

benchmark: *.cpp *.h verb-parse-perfhash.cpp
	$(CXX) $(FLAGS) benchmark.cpp http_verb.cpp -o $@

verb-parse-perfhash.cpp: http_verbs.gperf
	gperf --language=C++\
          --enum\
          --readonly-tables\
          --compare-strncmp\
          --class-name=perfect_hash_aux\
          --lookup-function-name=string_to_verb\
          --struct-type\
          --output-file=$@\
          http_verbs.gperf
	sed -i 's/^#line.*//g' $@
