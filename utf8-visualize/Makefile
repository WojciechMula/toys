FLAGS=-Wall -Wextra -std=c++17 -ggdb

ansi_printer: ansi_printer.cpp utf8_visitor.o
	$(CXX) $(FLAGS) utf8_visitor.o $< -o $@

utf8_visitor.o: utf8_visitor.cpp utf8_visitor.h
	$(CXX) $(FLAGS) -c $< -o $@
