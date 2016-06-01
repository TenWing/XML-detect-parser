CC=g++
CFLAGS=-W -Wall -std=c++11 -I src
LDFLAGS=
EXEC=parser.exe
SRC= $(wildcard src/*.cpp)
OBJ_RAW=$(patsubst src/%,build/%,$(SRC))
OBJ= $(OBJ_RAW:.cpp=.o)

all: $(EXEC)

$(EXEC): 	$(OBJ)
			@$(CC) -o $@ $^ $(LDFLAGS)

build/%.o: 	src/%.cpp
			@$(CC) -o $@ -c $< $(CFLAGS)

.PHONY: 	clean mrproper

clean:
			@rm -rf build/*.o

mrproper: 	clean
			@rm -rf $(EXEC)