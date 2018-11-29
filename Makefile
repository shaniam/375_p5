All: test

main: main.cpp 
	g++ -Wall -g -o main main.cpp

test: 
	g++ -Wall -g mergetest.h mergetest.cpp qspartitions.h qspartitions.cpp test.cpp -o test


clean:
	rm -rf *.txt
	rm test
checkmem:All
	valgrind ./merge

gdb: test
	gdb -x gdb_cmds.out test


run:All
	./merge
