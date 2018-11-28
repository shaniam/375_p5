All: main merge

main: main.cpp
	g++ -Wall -g -o main main.cpp

merge: mergetest.cpp
	g++ -Wall -g -o merge mergetest.cpp

clean:
	rm -rf *.txt
	rm test
	rm merge
checkmem:All
	valgrind ./merge

gdb: merge
	gdb -x gdb_cmds.txt merge


run:All
	./merge
