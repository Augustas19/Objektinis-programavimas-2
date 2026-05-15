programa: vector.cpp funkcijos.cpp
	g++ vector.cpp funkcijos.cpp studentas.cpp -o programa
testas: test.cpp funkcijos.cpp studentas.cpp catch_amalgamated.cpp
	g++ test.cpp funkcijos.cpp studentas.cpp catch_amalgamated.cpp -o testai
clean:
	rm -f programa
	rm -f testai