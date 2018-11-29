#ifndef MERGETEST_H
#define MERGETEST_H
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

using namespace std;

void merge( vector< pair<int,char> > &A, int low, int mid, int high);
void mergeSort(vector< pair<int, char> > &A, int p, int r);
void tripartMerge(vector< pair<int, char> > &A, int low, int mid, int high, int size);
void tripartMSort(vector< pair<int, char> > &A, int p, int r);

#endif