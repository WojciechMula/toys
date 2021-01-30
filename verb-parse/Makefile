FLAGS=-Wall -Wextra -std=c++17 -O3 -march=native

run: benchmark
	./benchmark 100 10000
	./benchmark 1000 1000
	./benchmark 10000 100

benchmark: *.cpp *.h verb-parse-perfhash.cpp
	$(CXX) $(FLAGS) benchmark.cpp http_verb.cpp -o $@

verb-parse-perfhash.in.cpp: http_verbs.txt
	gperf --language=C++\
          --enum\
          --readonly-tables\
          --compare-strncmp\
          --class-name=perfect_hash\
          --lookup-function-name=string_to_verb\
          --output-file=$@\
          http_verbs.txt
	sed -i 's/register//g' $@
