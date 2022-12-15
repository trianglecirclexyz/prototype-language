
CXX = g++

OBJ = ./obj
BIN = ./bin
INC = ./inc
SRC = ./src
TESTSRC = ./testsrc

CXXFLAGS = -std=c++17 -I $(INC) -I /opt/local/include
LDFLAGS = -L /opt/local/lib -lgtest -lgtest_main

all: dirs run

run: $(BIN)/string_utils_test $(BIN)/lexer_test $(BIN)/transpiler
	$(BIN)/string_utils_test && $(BIN)/lexer_test


# Binaries
$(BIN)/transpiler: $(OBJ)/transpiler.o $(OBJ)/lexer.o $(OBJ)/string_utils.o
	$(CXX) $(LDFLAGS) $(OBJ)/transpiler.o $(OBJ)/lexer.o $(OBJ)/string_utils.o -o $(BIN)/transpiler


# Test Binaries
$(BIN)/string_utils_test: $(OBJ)/string_utils_test.o $(OBJ)/string_utils.o
	$(CXX) $(OBJ)/string_utils_test.o $(OBJ)/string_utils.o -o $(BIN)/string_utils_test $(LDFLAGS)

$(BIN)/lexer_test: $(OBJ)/lexer_test.o $(OBJ)/lexer.o $(OBJ)/string_utils.o
	$(CXX) $(OBJ)/lexer_test.o $(OBJ)/lexer.o $(OBJ)/string_utils.o -o $(BIN)/lexer_test $(LDFLAGS)

# Objects
$(OBJ)/transpiler.o: $(SRC)/transpiler.cpp $(INC)/lexer.h
	$(CXX) $(CXXFLAGS) -c $(SRC)/transpiler.cpp -o $(OBJ)/transpiler.o

$(OBJ)/lexer.o: $(SRC)/lexer.cpp $(INC)/lexer.h $(INC)/string_utils.h
	$(CXX) $(CXXFLAGS) -c $(SRC)/lexer.cpp -o $(OBJ)/lexer.o

$(OBJ)/string_utils.o: $(SRC)/string_utils.cpp $(INC)/string_utils.h
	$(CXX) $(CXXFLAGS) -c $(SRC)/string_utils.cpp -o $(OBJ)/string_utils.o


# Test Objects
$(OBJ)/string_utils_test.o: $(TESTSRC)/string_utils_test.cpp $(INC)/string_utils.h 
	$(CXX) $(CXXFLAGS) -c $(TESTSRC)/string_utils_test.cpp -o $(OBJ)/string_utils_test.o

$(OBJ)/lexer_test.o: $(TESTSRC)/lexer_test.cpp $(INC)/lexer.h 
	$(CXX) $(CXXFLAGS) -c $(TESTSRC)/lexer_test.cpp -o $(OBJ)/lexer_test.o


# Miscellaneous
dirs:
	mkdir -p $(BIN)
	mkdir -p $(OBJ)

clean:
	rm -rf $(BIN) $(OBJ)