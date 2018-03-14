.PHONY: clean
.PHONY: help

test: demo
	./demo < /usr/share/dict/words

demo: stdmap-speedup.cpp
	$(CXX) -O3 $^ -o $@

clean:
	$(RM) demo
