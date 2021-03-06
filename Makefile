CXX=g++
CXXFLAGS=
LDFLAGS=-lBigInt

LIB_DIR=./libBigInt/lib/
INCLUDE_DIR=./libBigInt/include/
SRC_DIR=./libBigInt/src/
OBJ_DIR=./libBigInt/obj/

all: ./bin/calculatrice ./bin/genererNombre

./bin/calculatrice: $(LIB_DIR)libBigInt.a ./src/calculatrice.cpp
	$(CXX) -o $@ -I $(INCLUDE_DIR) -L $(LIB_DIR) ./src/calculatrice.cpp $(CXXFLAGS) $(LDFLAGS)

$(LIB_DIR)libBigInt.a: $(OBJ_DIR)entier.o
	ar rv $@ $^

$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp $(INCLUDE_DIR)%.hpp
	$(CXX) -o $@ -I $(INCLUDE_DIR) -c $< $(CXXFLAGS)

./bin/genererNombre: ./src/genererNombre.cpp
	$(CXX) -o $@ $< -W -Wall -pedantic -ansi

.PHONY: clean mrproper

clean:
	rm -f $(OBJ_DIR)*.o

mrproper: clean
	rm -f ./bin/calculatrice
	rm -f ./bin/genererNombre
