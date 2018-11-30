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

int main(){
	char alpha;
	int x;
	int y;
	vector<pair<int, char>> test;
	vector<pair<int, char>> qs;
	for (int i=0; i<100; i++){
		x = rand() % 100 +1;
		y = rand() % 26 + 97;
		alpha = (char) y;
		test.push_back(make_pair(x, alpha));
	}
	ofstream input1;
	input1.open("input1.txt");
	input1 << "1" << " 100" << endl;
	for (auto x : test){
		input1 << x.first << " " << x.second << endl;
	}
	qs=test;
	ofstream qoutput1;
	qoutput1.open("qsoutput1.txt");
	input1.close();
	stable_sort(test.begin(), test.end());
	ofstream answer1;
	answer1.open("correct_stable_input1.txt");
	ofstream answerone;
	quickSort(qs, 0, qs.size()-1, 0);
	answerone.open("correct_input1.txt");
	for (auto x: test){
		answer1 << x.first << " " << x.second << endl;
		answerone << x.first << endl;
	}
	for (auto x: qs){
		qoutput1 << x.first << endl;
	}

	answer1.close();
	answerone.close();
	qoutput1.close();
}
