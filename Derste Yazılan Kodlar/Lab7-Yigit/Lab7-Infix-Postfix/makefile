hespi: derle calistir

derle:
	g++ -I ./include/ -o ./lib/Hata.o -c ./src/Hata.cpp
	g++ -I ./include/ -o ./lib/Postfix.o -c ./src/Postfix.cpp
	g++ -I ./include/ -o ./bin/Test ./lib/Hata.o ./lib/Postfix.o ./src/Test.cpp
	
calistir:
	./bin/Test