Q=linear
R=complexity
S=qspartitions
CFLAGS= -Wall -Wextra -DDEBUG -g -pedantic -std=c++14

all: $(Q).o $(S).o $(R)

$(Q).o: $(Q).cpp $(Q).h
	g++ $(CFLAGS) -o $(Q).o -c $(Q).cpp

$(R): $(R).o $(Q).o $(S).o
	g++ $(CFLAGS) -o $(R) $(R).o

$(R).o: $(R).cpp $(Q).o $(S).o
	g++ $(CFLAGS) -o $(R).o -c $(R).cpp

$(S).o: $(S).cpp
	g++ $(CFLAGS) -o $(S).o -c $(S).cpp

run: all
	./$(R)

clean:
	rm -rf *.o
	rm -rf $(Q)
	rm -rf *~
	rm -rf *.cpp~
	rm -rf *.h~
