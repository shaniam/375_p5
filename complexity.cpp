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
	for(int i = 100; i < 10000001; i *= 10){
	cout << "i: " << i << endl;
	int nums = 1000;
	arg=generate(i, nums);

	auto start = chrono::high_resolution_clock::now();
	tripartMSort(arg, 1, arg.size());
	auto finish = chrono::high_resolution_clock::now();
	chrono::duration<double, std::milli> elapsed = finish - start;
	cout << "Merge Sort 3 way: "<< i << "," << elapsed.count() << endl;

	start = chrono::high_resolution_clock::now();
	mergeSort(arg, 1, arg.size());
	finish = chrono::high_resolution_clock::now();
	elapsed = finish - start;
	cout << "Merge Sort 2 way: "<< i << "," << elapsed.count() << endl;


	//for (int i=0; i<1000; i++){

		// start = chrono::high_resolution_clock::now();
		// //arg=generate(i,100);
		// quickSort(arg, 0, arg.size()-1, 0);
		// start = chrono::high_resolution_clock::now();
		// cout << "Last Pivot: " << i << "," << elapsed.count() << endl;
	//}
	//for (int i=0; i < 1000; i++){
              //arg=generate(i, nums);
                start = chrono::high_resolution_clock::now();
                //arg=generate(i,100);
                quickSort(arg, 0, arg.size()-1, 1);
                finish = chrono::high_resolution_clock::now();
								elapsed = finish - start;
               	cout << "Random Pivot: " << i << "," << elapsed.count() << endl;
      //  }
	//for (int i=0; i<1000; i++){
                //arg=generate(i, nums);
                start = chrono::high_resolution_clock::now();
                //arg=generate(i,100);
                quickSort(arg, 0, arg.size()-1, 1);
                finish = chrono::high_resolution_clock::now();
								elapsed = finish - start;
                cout << "Hoare's Pivot: "<< i << "," << elapsed.count() << endl;

								start = chrono::high_resolution_clock::now();
								//arg=generate(i,100);
								//quickSort(arg, 0, arg.size()-1, 0);
								finish = chrono::high_resolution_clock::now();
								elapsed = finish - start;
								cout << "Last Pivot: " << i << "," << elapsed.count() << endl;
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
			start = chrono::high_resolution_clock::now();
			radixSort(arg, 4, nums);
			finish = chrono::high_resolution_clock::now();
			elapsed = finish - start;
			radixFile4 << i << "," << elapsed.count() << endl;

			//Radix, d = 8
			start = chrono::high_resolution_clock::now();
			radixSort(arg, 8, nums);
			finish = chrono::high_resolution_clock::now();
			elapsed = finish - start;
			cout << "Radix 4: "<< i << "," << elapsed.count() << endl;

			//Radix, d = 16
			start = chrono::high_resolution_clock::now();
			radixSort(arg, 16, nums);
			finish = chrono::high_resolution_clock::now();
			elapsed = finish - start;
			cout << "Radix 16: " << i << "," << elapsed.count() << endl;

			//Radix, d = 32
			start = chrono::high_resolution_clock::now();
			radixSort(arg, 32, nums);
			finish = chrono::high_resolution_clock::now();
			elapsed = finish - start;
			cout << "Radix 32: "<< i << "," << elapsed.count() << endl;

			//Pidgeonhole
			start = chrono::high_resolution_clock::now();
			pidgeonholeSort(arg, nums, i);
			finish = chrono::high_resolution_clock::now();
			elapsed = finish - start;
			cout << "Pidgeonhole: "<< i << "," << elapsed.count() << endl;
			cout << endl;
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

}
