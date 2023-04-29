FLAGS=-Wall -Wextra -pedantic -std=c++17 -march=skylake
SRC=generated/hash_ada.cpp generated/hash_ada-pred.cpp generated/hash_ada-res.cpp generated/hash_adadefs.cpp generated/hash_c.cpp generated/hash_countries.cpp generated/hash_cplusplus.cpp generated/hash_cpp.cpp generated/hash_go.cpp generated/hash_gpc.cpp generated/hash_irc.cpp generated/hash_java.cpp generated/hash_jscript.cpp generated/hash_modula.cpp generated/hash_modula2.cpp generated/hash_modula3.cpp generated/hash_pascal.cpp generated/hash_sneller.cpp generated/hash_snellerbuiltin.cpp generated/hash_states.cpp generated/pext_ada.cpp generated/pext_ada-pred.cpp generated/pext_ada-res.cpp generated/pext_adadefs.cpp generated/pext_c.cpp generated/pext_countries.cpp generated/pext_cplusplus.cpp generated/pext_cpp.cpp generated/pext_go.cpp generated/pext_gpc.cpp generated/pext_irc.cpp generated/pext_java.cpp generated/pext_jscript.cpp generated/pext_modula.cpp generated/pext_modula2.cpp generated/pext_modula3.cpp generated/pext_pascal.cpp generated/pext_sneller.cpp generated/pext_snellerbuiltin.cpp generated/pext_states.cpp generated/split_ada.cpp generated/split_ada-pred.cpp generated/split_ada-res.cpp generated/split_adadefs.cpp generated/split_c.cpp generated/split_countries.cpp generated/split_cplusplus.cpp generated/split_cpp.cpp generated/split_go.cpp generated/split_gpc.cpp generated/split_irc.cpp generated/split_java.cpp generated/split_jscript.cpp generated/split_modula.cpp generated/split_modula2.cpp generated/split_modula3.cpp generated/split_pascal.cpp generated/split_sneller.cpp generated/split_snellerbuiltin.cpp generated/split_states.cpp
all: unittest benchmark

unittest: unittest.cpp
	$(CXX) $(FLAGS) unittest.cpp -o unittest

unittest.cpp: unittest.py $(SRC)
	python3 unittest.py

benchmark: benchmark.cpp benchmark.cpp.in
	$(CXX) $(FLAGS) -O2 benchmark.cpp -o benchmark

benchmark.cpp.in: benchmark.py $(SRC)
	python3 benchmark.py

generated/hash_ada.cpp: datasets/ada.txt hash/main
	hash/main -i datasets/ada.txt -o generated/hash_ada.cpp

generated/hash_ada-pred.cpp: datasets/ada-pred.txt hash/main
	hash/main -i datasets/ada-pred.txt -o generated/hash_ada-pred.cpp

generated/hash_ada-res.cpp: datasets/ada-res.txt hash/main
	hash/main -i datasets/ada-res.txt -o generated/hash_ada-res.cpp

generated/hash_adadefs.cpp: datasets/adadefs.txt hash/main
	hash/main -i datasets/adadefs.txt -o generated/hash_adadefs.cpp

generated/hash_c.cpp: datasets/c.txt hash/main
	hash/main -i datasets/c.txt -o generated/hash_c.cpp

generated/hash_countries.cpp: datasets/countries.txt hash/main
	hash/main -i datasets/countries.txt -o generated/hash_countries.cpp

generated/hash_cplusplus.cpp: datasets/cplusplus.txt hash/main
	hash/main -i datasets/cplusplus.txt -o generated/hash_cplusplus.cpp

generated/hash_cpp.cpp: datasets/cpp.txt hash/main
	hash/main -i datasets/cpp.txt -o generated/hash_cpp.cpp

generated/hash_go.cpp: datasets/go.txt hash/main
	hash/main -i datasets/go.txt -o generated/hash_go.cpp

generated/hash_gpc.cpp: datasets/gpc.txt hash/main
	hash/main -i datasets/gpc.txt -o generated/hash_gpc.cpp

generated/hash_irc.cpp: datasets/irc.txt hash/main
	hash/main -i datasets/irc.txt -o generated/hash_irc.cpp

generated/hash_java.cpp: datasets/java.txt hash/main
	hash/main -i datasets/java.txt -o generated/hash_java.cpp

generated/hash_jscript.cpp: datasets/jscript.txt hash/main
	hash/main -i datasets/jscript.txt -o generated/hash_jscript.cpp

generated/hash_modula.cpp: datasets/modula.txt hash/main
	hash/main -i datasets/modula.txt -o generated/hash_modula.cpp

generated/hash_modula2.cpp: datasets/modula2.txt hash/main
	hash/main -i datasets/modula2.txt -o generated/hash_modula2.cpp

generated/hash_modula3.cpp: datasets/modula3.txt hash/main
	hash/main -i datasets/modula3.txt -o generated/hash_modula3.cpp

generated/hash_pascal.cpp: datasets/pascal.txt hash/main
	hash/main -i datasets/pascal.txt -o generated/hash_pascal.cpp

generated/hash_sneller.cpp: datasets/sneller.txt hash/main
	hash/main -i datasets/sneller.txt -o generated/hash_sneller.cpp

generated/hash_snellerbuiltin.cpp: datasets/snellerbuiltin.txt hash/main
	hash/main -i datasets/snellerbuiltin.txt -o generated/hash_snellerbuiltin.cpp

generated/hash_states.cpp: datasets/states.txt hash/main
	hash/main -i datasets/states.txt -o generated/hash_states.cpp

generated/pext_ada.cpp: datasets/ada.txt pext/main
	pext/main -i datasets/ada.txt -o generated/pext_ada.cpp

generated/pext_ada-pred.cpp: datasets/ada-pred.txt pext/main
	pext/main -i datasets/ada-pred.txt -o generated/pext_ada-pred.cpp

generated/pext_ada-res.cpp: datasets/ada-res.txt pext/main
	pext/main -i datasets/ada-res.txt -o generated/pext_ada-res.cpp

generated/pext_adadefs.cpp: datasets/adadefs.txt pext/main
	pext/main -i datasets/adadefs.txt -o generated/pext_adadefs.cpp

generated/pext_c.cpp: datasets/c.txt pext/main
	pext/main -i datasets/c.txt -o generated/pext_c.cpp

generated/pext_countries.cpp: datasets/countries.txt pext/main
	pext/main -i datasets/countries.txt -o generated/pext_countries.cpp

generated/pext_cplusplus.cpp: datasets/cplusplus.txt pext/main
	pext/main -i datasets/cplusplus.txt -o generated/pext_cplusplus.cpp

generated/pext_cpp.cpp: datasets/cpp.txt pext/main
	pext/main -i datasets/cpp.txt -o generated/pext_cpp.cpp

generated/pext_go.cpp: datasets/go.txt pext/main
	pext/main -i datasets/go.txt -o generated/pext_go.cpp

generated/pext_gpc.cpp: datasets/gpc.txt pext/main
	pext/main -i datasets/gpc.txt -o generated/pext_gpc.cpp

generated/pext_irc.cpp: datasets/irc.txt pext/main
	pext/main -i datasets/irc.txt -o generated/pext_irc.cpp

generated/pext_java.cpp: datasets/java.txt pext/main
	pext/main -i datasets/java.txt -o generated/pext_java.cpp

generated/pext_jscript.cpp: datasets/jscript.txt pext/main
	pext/main -i datasets/jscript.txt -o generated/pext_jscript.cpp

generated/pext_modula.cpp: datasets/modula.txt pext/main
	pext/main -i datasets/modula.txt -o generated/pext_modula.cpp

generated/pext_modula2.cpp: datasets/modula2.txt pext/main
	pext/main -i datasets/modula2.txt -o generated/pext_modula2.cpp

generated/pext_modula3.cpp: datasets/modula3.txt pext/main
	pext/main -i datasets/modula3.txt -o generated/pext_modula3.cpp

generated/pext_pascal.cpp: datasets/pascal.txt pext/main
	pext/main -i datasets/pascal.txt -o generated/pext_pascal.cpp

generated/pext_sneller.cpp: datasets/sneller.txt pext/main
	pext/main -i datasets/sneller.txt -o generated/pext_sneller.cpp

generated/pext_snellerbuiltin.cpp: datasets/snellerbuiltin.txt pext/main
	pext/main -i datasets/snellerbuiltin.txt -o generated/pext_snellerbuiltin.cpp

generated/pext_states.cpp: datasets/states.txt pext/main
	pext/main -i datasets/states.txt -o generated/pext_states.cpp

generated/split_ada.cpp: datasets/ada.txt split/main
	split/main -i datasets/ada.txt -o generated/split_ada.cpp

generated/split_ada-pred.cpp: datasets/ada-pred.txt split/main
	split/main -i datasets/ada-pred.txt -o generated/split_ada-pred.cpp

generated/split_ada-res.cpp: datasets/ada-res.txt split/main
	split/main -i datasets/ada-res.txt -o generated/split_ada-res.cpp

generated/split_adadefs.cpp: datasets/adadefs.txt split/main
	split/main -i datasets/adadefs.txt -o generated/split_adadefs.cpp

generated/split_c.cpp: datasets/c.txt split/main
	split/main -i datasets/c.txt -o generated/split_c.cpp

generated/split_countries.cpp: datasets/countries.txt split/main
	split/main -i datasets/countries.txt -o generated/split_countries.cpp

generated/split_cplusplus.cpp: datasets/cplusplus.txt split/main
	split/main -i datasets/cplusplus.txt -o generated/split_cplusplus.cpp

generated/split_cpp.cpp: datasets/cpp.txt split/main
	split/main -i datasets/cpp.txt -o generated/split_cpp.cpp

generated/split_go.cpp: datasets/go.txt split/main
	split/main -i datasets/go.txt -o generated/split_go.cpp

generated/split_gpc.cpp: datasets/gpc.txt split/main
	split/main -i datasets/gpc.txt -o generated/split_gpc.cpp

generated/split_irc.cpp: datasets/irc.txt split/main
	split/main -i datasets/irc.txt -o generated/split_irc.cpp

generated/split_java.cpp: datasets/java.txt split/main
	split/main -i datasets/java.txt -o generated/split_java.cpp

generated/split_jscript.cpp: datasets/jscript.txt split/main
	split/main -i datasets/jscript.txt -o generated/split_jscript.cpp

generated/split_modula.cpp: datasets/modula.txt split/main
	split/main -i datasets/modula.txt -o generated/split_modula.cpp

generated/split_modula2.cpp: datasets/modula2.txt split/main
	split/main -i datasets/modula2.txt -o generated/split_modula2.cpp

generated/split_modula3.cpp: datasets/modula3.txt split/main
	split/main -i datasets/modula3.txt -o generated/split_modula3.cpp

generated/split_pascal.cpp: datasets/pascal.txt split/main
	split/main -i datasets/pascal.txt -o generated/split_pascal.cpp

generated/split_sneller.cpp: datasets/sneller.txt split/main
	split/main -i datasets/sneller.txt -o generated/split_sneller.cpp

generated/split_snellerbuiltin.cpp: datasets/snellerbuiltin.txt split/main
	split/main -i datasets/snellerbuiltin.txt -o generated/split_snellerbuiltin.cpp

generated/split_states.cpp: datasets/states.txt split/main
	split/main -i datasets/states.txt -o generated/split_states.cpp

hash/main: hash/*.go
	go build -C hash

pext/main: pext/*.go
	go build -C pext

split/main: split/*.go
	go build -C split
