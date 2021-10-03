CC = g++
CFLAGS = -O3 -Wall

SOURCE_PATH = source/complex.cpp
TEST_PATH = test/UnitTest.cpp
MAIN_PATH = main/main.cpp

OBJECTS = main.o complex.o UnitTest.o
EXECUTABLE = Complex

.PHONY: all install uninstall clean

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(EXECUTABLE) 

main.o: $(MAIN_PATH)
	$(CC) $(CFLAGS) -c $(MAIN_PATH) -o main.o

complex.o: $(SOURCE_PATH)
	$(CC) $(CFLAGS) -c $(SOURCE_PATH) -o complex.o 

UnitTest.o: $(TEST_PATH)
	$(CC) $(CFLAGS) -c $(TEST_PATH) -o UnitTest.o

install:
	install $(EXECUTABLE)
uninstall:
	rm -rf $(EXECUTABLE)
clean:
	rm -rf *.o $(EXECUTABLE)
	