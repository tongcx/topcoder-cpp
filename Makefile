test: *.cpp **/*.cpp
	g++ -std=c++11 -lgtest test_main.cpp -otest
	./test
