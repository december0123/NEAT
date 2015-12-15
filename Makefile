CC=g++
CFLAGS=-Wall -pedantic -std=c++1y -I `pwd`

all:
	echo "Nothing yet"

build/neat.o:
	$(CC) $(CFLAGS) -c src/neat.cpp -o build/neat.o

build/neatgenome.o:
	$(CC) $(CFLAGS) -c src/neatgenome.cpp -o build/neatgenome.o

build/neatinnovationdatabase.o:
	$(CC) $(CFLAGS) -c src/neatneuroninnovation.cpp -o build/neatinnovationdatabase.o

build/neatneuroninnovation.o:
	$(CC) $(CFLAGS) -c src/neatneuroninnovation.cpp -o build/neatneuroninnovation.o

build/neatlinkinnovation.o:
	$(CC) $(CFLAGS) -c src/neatlinkinnovation.cpp -o build/neatlinkinnovation.o

clean:
	rm -rf build/*