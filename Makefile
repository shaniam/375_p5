All: main merge

main: main.cpp
	g++ -Wall -g -o main main.cpp

merge: mergetest.cpp
	g++ -Wall -g -o merge mergetest.cpp

clean:
	rm -rf *.txt
	rm -rf *.csv
	rm test
	rm merge
checkmem:All
	valgrind ./merge

gdb: test
	gdb -x gdb_cmds.txt merge


run:All
	./merge
