CC = g++
EXEC = Pong
FLAGS = -Wall -Werror -pedantic
LIBS = -lsfml-graphics -lsfml-window -lsfml-system
STD = -std=c++17
S = src
O = obj
B = bin

all: $(O) $(B) $(O)/main.o
	$(CC) $(O)/*.o -o $(B)/$(EXEC) $(LIBS)

$(O)/main.o: $(O)/Game.o
	$(CC) $(S)/main.cpp -c -o $(O)/main.o $(STD) $(FLAGS)

$(O)/Game.o: $(O)/Player.o $(O)/Ball.o
	$(CC) $(S)/Game.cpp -c -o $(O)/Game.o $(STD) $(FLAGS)
	
$(O)/Player.o:
	$(CC) $(S)/Player.cpp -c -o $(O)/Player.o $(STD) $(FLAGS)
	
$(O)/Ball.o:
	$(CC) $(S)/Ball.cpp -c -o $(O)/Ball.o $(STD) $(FLAGS)
	
clean: $(O) $(B)
	rm -r $(O)
	rm -r $(B)

$(O):
	mkdir $(O)

$(B):
	mkdir $(B)

