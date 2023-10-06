Program: Derle Calistir
Derle:
	g++ -I ./include/ -o ./lib/dugum.o -c ./src/dugum.cpp
	g++ -I ./include/ -o ./lib/Liste.o -c ./src/Liste.cpp
	g++ -I ./include/ -o ./bin/uyg ./lib/dugum.o ./lib/Liste.o ./src/main.cpp
Calistir:
	./bin/uyg.exe

