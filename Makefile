CXX=g++
CXXFLAGS=-W -Wall -ansii -pedantics
LDFLAGS=-lBigInt

LIB_DIR=./libBigInt/lib/
INCLUDE_DIR=./libBigInt/include/
SRC_DIR=./libBigInt/src/
OBJ_DIR=./libBigInt/obj/

all: ./bin/calculatrice

./bin/calculatrice: $(LIB_DIR)libBigInt.a ./src/calculatrice.cpp
	$(CXX) -o $@ -I $(INCLUDE_DIR) -L $(LIB_DIR) ./src/calculatrice.cpp $(LDFLAGS)

$(LIB_DIR)libBigInt.a: $(OBJ_DIR)entier.o
	ar rv $@ $^

$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp $(INCLUDE_DIR)%.hpp
	$(CXX) -o $@ -I $(INCLUDE_DIR) -c $<

.PHONY: clean mrproper

clean:
	rm -f $(OBJ_DIR)*.o

mrproper: clean
	rm -f ./bin/calculatrice
