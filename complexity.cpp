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
	ofstream myfile;
	myfile.open("lastindex.csv", ios_base::app);
	for (int i=0; i<1000; i++){
		begin=clock();
		arg=generate(i,100);
		quickSort(arg, 0, arg.size()-1, 0);
		end=clock();
		myfile << i << "," << (float)(1000 * end-begin) / CLOCKS_PER_SEC   << endl;
	}
	myfile.close();

}
