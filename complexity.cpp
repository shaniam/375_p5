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
#include "mergetest.h"
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
void print(vector<pair<int, char>> val){
	cerr << "{" ;
	for (auto x : val){
	cerr << x.first << "," ;
	}
	cerr << "}" << endl;
}

int main(){
	clock_t begin;
	clock_t end;
	vector<pair<int, char>> arg;
	ofstream myfile;
	ofstream mf1;
	ofstream mf2;
	ofstream mf3, mf4, mf5, mf6,mf7;
	#if 1
	myfile.open("lastpivot.csv");
	mf1.open("randompivot.csv");
	mf2.open("hoarsepivot.csv");
	mf3.open("mergesort.csv");
	mf4.open("worstlp.csv");
	mf5.open("worstrp.csv");
	mf6.open("worsthp.csv");
	mf7.open("sortedmergesort.csv");
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
	for (int i=0; i<5000; i++){
                arg=generate(i,100); 
                begin=clock();
                mergeSort(arg, 0, arg.size());
                end=clock();
                mf3 << i << "," << (float)(1000 * end-begin) / CLOCKS_PER_SEC << endl;
        }
	arg={};
	for (int i=0; i<1000; i++){
		arg.push_back(make_pair(i, 'a'));
		begin=clock();
                quickSort(arg, 0, arg.size()-1, 0);
                end=clock();
                mf4 << i << "," << (float)(1000 * end-begin) / CLOCKS_PER_SEC << endl;
	}
	arg={};
	for (int i=0; i<1000; i++){
		arg.push_back(make_pair(i,'a'));
		begin=clock();
		quickSort(arg, 0, arg.size()-1, 1);
		end=clock();
		mf5 << i << "," << (float)(1000 * end-begin)/ CLOCKS_PER_SEC << endl;

	}
	//arg.reserve(1000);
	arg={};
	vector<pair<int, char>> ret;
	for (int i=0; i<1000; i++){
		arg.push_back(make_pair(i,'a'));
		ret=arg;
                begin=clock();
               	quickSort(ret, 0, arg.size()-1, 2);
                end=clock();
		//print(arg);
		mf6 << i << "," << (float)(1000 * end-begin)/  CLOCKS_PER_SEC << endl;
	}
	arg={};
	for (int i=0; i<1000; i++){
                arg.push_back(make_pair(i,'a'));
                begin=clock();
                mergeSort(ret, 0, arg.size());
                end=clock();
                //print(arg);
                mf7 << i << "," << (float)(1000 * end-begin)/  CLOCKS_PER_SEC << endl;
        }
	#endif
#if 0	
	arg={make_pair(7,'a'),make_pair(6,'a'),make_pair(5,'a'),make_pair(4,'a'),make_pair(3,'a'),make_pair(2,'a'),make_pair(1,'a')};
	//1 == hoars partition
	quickSort(arg, 0, arg.size()-1,0);
	print(arg);
#endif
	myfile.close();
	mf1.close();
	mf2.close();
	mf3.close();
	mf4.close();
	mf5.close();
	mf6.close();
	mf7.close();
}
