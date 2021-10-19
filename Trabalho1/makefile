UTIL=game.c catalog.c list.c
MAIN=main.c
BINARY=main

all:
	gcc -Wall -g $(UTIL) $(MAIN) -o $(BINARY)

run:
	./$(BINARY)

debug:
	gcc -DDEBUG -Wall $(MAIN) $(UTIL) -o $(BINARY)

valgrind:
	valgrind --tool=memcheck --leak-check=full  --track-origins=yes --show-leak-kinds=all --show-reachable=yes ./$(BINARY)

clean:
	@rm *.o
