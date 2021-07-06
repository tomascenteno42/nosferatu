CC = g++
PROG_NAME = NosferatuV2
VALGRIND = valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --log-file=valgrind-out.txt
SRC = *.cpp
FLAG = -Wall -Wconversion -ggdb3 -Wpedantic -g --std=c++14

run: compile
	./$(PROG_NAME)
compile:
	$(CC) $(FLAG) $(SRC) -o $(PROG_NAME)
valgrind:
	$(VALGRIND) ./$(PROG_NAME)
