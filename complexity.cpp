#include <iostream>
#include <utility>
#include <iostream>
#include <string.h>
#include <fstream>
#include <vector>
#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <chrono>
#include <cstdlib>
#include <functional>
#include <time.h>
#include <stdlib.h>
#include "qspartitions.h"
#include "linear.h"
#include "mergetest.h"

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
	vector<pair<int, char>> arg;
	ofstream myfile, mf1, mf2, pidgeonholeFile, radixFile2, radixFile4, radixFile8, radixFile16, radixFile32, tripartMerge, merge;
	tripartMerge.open("threewayMergeSort.csv");
	merge.open("standardMergeSort.csv");
	myfile.open("lastpivot.csv");
	mf1.open("randompivot.csv");
	mf2.open("hoarsepivot.csv");
	pidgeonholeFile.open("pidgeonhole.csv");
	radixFile2.open("radixSort2.csv");
	radixFile4.open("radixSort4.csv");
	radixFile8.open("radixSort8.csv");
	radixFile16.open("radixSort16.csv");
	radixFile32.open("radixSort32.csv");

	for(int i = 1; i < 1001; i++){
	cout << "i: " << i << endl;
	int nums = 1000;
	arg=generate(i, nums);

	chrono::duration<double, std::milli> elapsed;

	auto start = chrono::high_resolution_clock::now();
	auto finish = chrono::high_resolution_clock::now();
	double average = 0;
	for(int j = 0; j<10; j++){

		start = chrono::high_resolution_clock::now();
		tripartMSort(arg, 1, arg.size());
		finish = chrono::high_resolution_clock::now();
		elapsed = finish - start;
		average += elapsed.count();

	}
	tripartMerge << "Merge Sort 3 way: "<< i << "," << average/(double)10 << endl;


	average = 0;
	for(int j = 0; j<10; j++){
	start = chrono::high_resolution_clock::now();
	mergeSort(arg, 1, arg.size());
	finish = chrono::high_resolution_clock::now();
	elapsed = finish - start;
	average += elapsed.count();

	}
	merge << "Merge Sort 2 way: "<< i << "," << average/(double)10 << endl;

	/*
	average = 0;
	for (int j=0; i<10; j++){

		start = chrono::high_resolution_clock::now();
		// //arg=generate(i,100);
		quickSort(arg, 0, arg.size()-1, 0);
		start = chrono::high_resolution_clock::now();
		myfile << "Last Pivot: " << i << "," << elapsed.count() << endl;
	}
	*/
	//for (int i=0; i < 1000; i++){
              //arg=generate(i, nums);
	average = 0;
	for(int j = 0; j<10; j++){
    start = chrono::high_resolution_clock::now();
                //arg=generate(i,100);
    quickSort(arg, 0, arg.size()-1, 1);
    finish = chrono::high_resolution_clock::now();
	elapsed = finish - start;
	average += elapsed.count();
	}
    mf1 << "Random Pivot: " << i << "," << average/(double)10 << endl;
      //  }
	//for (int i=0; i<1000; i++){
                //arg=generate(i, nums);
    			average = 0;
				for(int j = 0; j<10; j++){
                start = chrono::high_resolution_clock::now();
                //arg=generate(i,100);
                quickSort(arg, 0, arg.size()-1, 1);
                finish = chrono::high_resolution_clock::now();
								elapsed = finish - start;
                mf2 << "Hoare's Pivot: "<< i << "," << elapsed.count() << endl;

								start = chrono::high_resolution_clock::now();
								//arg=generate(i,100);
								//quickSort(arg, 0, arg.size()-1, 0);
								finish = chrono::high_resolution_clock::now();
								elapsed = finish - start;
								average += elapsed.count();
				}
								myfile << "Last Pivot: " << i << "," << average/(double)10 << endl;
      //  }



	//for(int i = 0; i < 1000; i++){

			//arg=generate(i, nums);

			// //Radix, d = 2
			// start = chrono::high_resolution_clock::now();
			// radixSort(arg, 2, nums);
			// finish = chrono::high_resolution_clock::now();
			// cout << "Radix 2: "<< i << "," << elapsed.count() << endl;
			// //
			//Radix - Counting Sort, d = 4
			average = 0;
			for(int j = 0; j<10; j++){
			start = chrono::high_resolution_clock::now();
			radixSort(arg, 4, nums);
			finish = chrono::high_resolution_clock::now();
			elapsed = finish - start;
			average+=elapsed.count();
			}
			radixFile4 << "Radix 4" << i << "," << average/(double)10 << endl;

			//Radix, d = 8
			average = 0;
			for(int j = 0; j<10; j++){
			start = chrono::high_resolution_clock::now();
			radixSort(arg, 8, nums);
			finish = chrono::high_resolution_clock::now();
			elapsed = finish - start;
			average+=elapsed.count();
			}
			radixFile8 << "Radix 8: "<< i << "," << average/(double)10 << endl;

			//Radix, d = 16
			average = 0;
			for(int j = 0; j<10; j++){
			start = chrono::high_resolution_clock::now();
			radixSort(arg, 16, nums);
			finish = chrono::high_resolution_clock::now();
			elapsed = finish - start;
			average+=elapsed.count();
			}
			radixFile16 << "Radix 16: " << i << "," << average/(double)10 << endl;

			//Radix, d = 32
			average = 0;
			for(int j = 0; j<10; j++){
			start = chrono::high_resolution_clock::now();
			radixSort(arg, 32, nums);
			finish = chrono::high_resolution_clock::now();
			elapsed = finish - start;
			average+=elapsed.count();
			}
			radixFile32 << "Radix 32: "<< i << "," << average/(double)10 << endl;

			//Pidgeonhole
			average = 0;
			for(int j = 0; j<10; j++){
			start = chrono::high_resolution_clock::now();
			pidgeonholeSort(arg, nums, i);
			finish = chrono::high_resolution_clock::now();
			elapsed = finish - start;
			average+=elapsed.count();
			}
			pidgeonholeFile << "Pidgeonhole: "<< i << "," << average/(double)10 << endl;
			//cout << endl;
		}
	//}

	myfile.close();
	mf1.close();
	mf2.close();
	pidgeonholeFile.close();
	radixFile2.close();
	radixFile4.close();
	radixFile8.close();
	radixFile16.close();
	radixFile32.close();
	tripartMerge.close();
	merge.close();

}
