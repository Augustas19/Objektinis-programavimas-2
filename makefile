programa: vector.cpp funkcijos.cpp studentas.cpp
	g++ vector.cpp funkcijos.cpp studentas.cpp -o programa

testas: testavimas.cpp funkcijos.cpp studentas.cpp catch_amalgamated.cpp
	g++ testavimas.cpp funkcijos.cpp studentas.cpp catch_amalgamated.cpp -o testai
clean:
	rm -f programa
	rm -f testai.exe