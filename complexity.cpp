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
	for (int i = 0; i < size; i++){
		x= rand() % range;
		y= (char) rand()% range;
		ret.push_back(make_pair(x,y));
	}
	return ret;


}

int main(){
	clock_t begin;
	clock_t end;
	vector<pair<int, char>> arg;
	ofstream myfile, mf1, mf2, pidgeonholeFile, radixFile2, radixFile4, radixFile8, radixFile16, radixFile32;
	myfile.open("lastpivot.csv");
	mf1.open("randompivot.csv");
	mf2.open("hoarsepivot.csv");
	pidgeonholeFile.open("pidgeonhole.csv");
	radixFile2.open("radixSort2.csv");
	radixFile4.open("radixSort4.csv");
	radixFile8.open("radixSort8.csv");
	radixFile16.open("radixSort16.csv");
	radixFile32.open("radixSort32.csv");
	for (int i=0; i<1000; i++){
		arg=generate(i,100);
		begin=clock();
		//arg=generate(i,100);
		quickSort(arg, 0, arg.size()-1, 0);
		end=clock();
		myfile << i << "," << (float)(1000 * end-begin) / CLOCKS_PER_SEC << endl;
	}
	for (int i=0; i < 1000; i++){
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
			cout << "I: " << i << endl;
			arg = generate(i, 100);

			//Radix, d = 2
			begin = clock();
			radixSort(arg, 2, 1000);
			end = clock();
			radixFile2 << i << "," << (float)(1000 * end - begin) / CLOCKS_PER_SEC << endl;
			//
			//Radix - Counting Sort, d = 4
			begin = clock();
			radixSort(arg, 4, 1000);
			end = clock();
			radixFile4 << i << "," << (float)(1000 * end - begin) / CLOCKS_PER_SEC << endl;

			//Radix, d = 8
			begin = clock();
			radixSort(arg, 8, 1000);
			end = clock();
			radixFile8 << i << "," << (float)(1000 * end - begin) / CLOCKS_PER_SEC << endl;

			//Radix, d = 16
			begin = clock();
			radixSort(arg, 16, 1000);
			end = clock();
			radixFile16 << i << "," << (float)(1000 * end - begin) / CLOCKS_PER_SEC << endl;

			//Radix, d = 32
			begin = clock();
			radixSort(arg, 32, 1000);
			end = clock();
			radixFile32 << i << "," << (float)(1000 * end - begin) / CLOCKS_PER_SEC << endl;

			//Pidgeonhole
			begin = clock();
			pidgeonholeSort(arg, 1000, i);
			end = clock();
			pidgeonholeFile << i << "," << (float)(1000 * end - begin) / CLOCKS_PER_SEC << endl;
	}

	myfile.close();
	mf1.close();
	mf2.close();
	pidgeonholeFile.close();
	radixFile2.close();
	radixFile4.close();
	radixFile8.close();
	radixFile16.close();
	radixFile32.close();

}
