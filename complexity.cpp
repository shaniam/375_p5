#include <iostream>
#include <utility>
#include <iostream>
#include <string.h>
#include <fstream>
#include <vector>
#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <functional>
#include <time.h>
#include <stdlib.h>
#include "qspartitions.h"
#include "linear.h"

using namespace std;

vector<pair<int,char>> generate(int size, int range){

	int x;
	char y;
	vector<pair< int, char>> ret={};
	for (int i = 0; i<size; i++){
		x= rand() % range +1;
		y= (char) rand()% range+1;
		ret.push_back(make_pair(x,y));
	}
	return ret;


}

int main(){
	clock_t begin;
	clock_t end;
	vector<pair<int, char>> arg;
	ofstream myfile, mf1, mf2, pidgeonholeFile, radixFile;
	myfile.open("lastpivot.csv");
	mf1.open("randompivot.csv");
	mf2.open("hoarsepivot.csv");
	pidgeonholeFile.open("pidgeonhole.csv");
	radixFile.open("radixSort.csv");
	for (int i=0; i<1000; i++){
		arg=generate(i,100);
		begin=clock();
		//arg=generate(i,100);
		quickSort(arg, 0, arg.size()-1, 0);
		end=clock();
		myfile << i << "," << (float)(1000 * end-begin) / CLOCKS_PER_SEC << endl;
	}
	for (int i=0; i<1000; i++){
                arg=generate(i,100);
                begin=clock();
                //arg=generate(i,100);
                quickSort(arg, 0, arg.size()-1, 1);
                end=clock();
               	mf1 << i << "," << (float)(1000 * end-begin) / CLOCKS_PER_SEC << endl;
        }
	for (int i=0; i<1000; i++){
                arg=generate(i,100);
                begin=clock();
                //arg=generate(i,100);
                quickSort(arg, 0, arg.size()-1, 1);
                end=clock();
                mf2 << i << "," << (float)(1000 * end-begin) / CLOCKS_PER_SEC << endl;
        }

	for(int i = 0; i < 1000; i++){
			arg = generate(i, 100);
			begin = clock();
			pidgeonholeSort(arg, 100, 100);
			end = clock();
			pidgeonholeFile << i << "," << (float)(1000 * end - begin) / CLOCKS_PER_SEC << endl;
	}

	for(int i = 0; i < 1000; i++){
			arg = generate(i, 100);
			begin = clock();
			radixSort(arg, 1, 100);
			end = clock();
			radixFile << i << "," << (float)(1000 * end - begin) / CLOCKS_PER_SEC << endl;
	}

	myfile.close();
	mf1.close();
	mf2.close();
	pidgeonholeFile.close();
	radixFile.close();
}
