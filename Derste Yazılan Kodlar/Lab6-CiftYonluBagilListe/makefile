hepsi: derle calistir
Nesneler :=  ./lib/Hata.o ./lib/Hatalar.o

derle:
	g++ -I ./include/ -o ./lib/Hata.o -c ./src/Hata.cpp
	g++ -I ./include/ -o ./lib/Hatalar.o -c ./src/Hatalar.cpp
	g++ -I ./include/ -o ./bin/test $(Nesneler) ./src/test.cpp
	
calistir:
	./bin/test