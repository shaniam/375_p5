Q=linear
R=complexity
S=qspartitions
CFLAGS= -Wall -Wextra -DDEBUG -g -pedantic -std=c++14

all: $(Q)

$(Q): $(Q).cpp
		g++ $(CFLAGS) $(Q).cpp -o $(Q)

$(Q).o: $(Q).cpp $(Q).h
	g++ $(CFLAGS) -o $(Q).o -c $(Q).cpp

$(R): $(R).cpp $(Q).cpp $(S).cpp
	g++ $(CFLAGS) $(R).cpp $(S).cpp $(Q).cpp -o $(R)

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
