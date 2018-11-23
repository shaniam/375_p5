All: merge

merge: mergetest.cpp
	g++ -Wall -g -o merge mergetest.cpp

clean:
	rm merge
	ls

checkmem:All
	valgrind ./merge

gdb: test
	gdb -x gdb_cmds.txt merge


run:All
	./merge
