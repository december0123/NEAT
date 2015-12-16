CC=g++
CFLAGS=-fPIC -Wall -Wextra -pedantic -std=c++14 -I`pwd`
BOOSTPYTHONFLAGS=-I/usr/include/python3.4m -I/usr/include/boost -lboost_python3 -lpython3.4m

all: build/neat.o build/neatgenome.o build/neatinnovationdatabase.o build/neatlinkinnovation.o build/neatneuroninnovation.o build/neatpythonwrapper.o
	$(CC) $(CFLAGS) $(BOOSTPYTHONFLAGS) src/pyneat.cpp -shared -std=c++14 -O3 -o neat.so build/neat.o build/neatgenome.o build/neatinnovationdatabase.o build/neatneuroninnovation.o build/neatlinkinnovation.o build/neatpythonwrapper.o

build/neatpythonwrapper.o:
	$(CC) $(CFLAGS) $(BOOSTPYTHONFLAGS) -c src/neatpythonwrapper.cpp -o build/neatpythonwrapper.o

build/neat.o:
	$(CC) $(CFLAGS) -c src/neat.cpp -o build/neat.o

build/neatgenome.o: 
	$(CC) $(CFLAGS) -c src/neatgenome.cpp -o build/neatgenome.o

build/neatinnovationdatabase.o:
	$(CC) $(CFLAGS) -c src/neatinnovationdatabase.cpp -o build/neatinnovationdatabase.o
	
build/neatneuroninnovation.o:
	$(CC) $(CFLAGS) -c src/neatneuroninnovation.cpp -o build/neatneuroninnovation.o

build/neatlinkinnovation.o:
	$(CC) $(CFLAGS) -c src/neatlinkinnovation.cpp -o build/neatlinkinnovation.o

clean:
	rm -rf build/*