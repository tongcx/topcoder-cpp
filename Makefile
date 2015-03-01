test: test_main.cpp number/test_ff.cpp
	g++ -std=c++11 -lgtest $^ -otest
	./test
