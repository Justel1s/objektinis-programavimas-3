main: studentai.o
	g++ -o vector vector.cpp studentai.o -O3 
test: studentai.o
	g++ -o test cppunit_test.cc studentai.o 
	./test
	rm test
studentai.o: funkcijos.cpp
	g++ -c funkcijos.cpp -o studentai.o
clean:
	rm *.o vector studentai