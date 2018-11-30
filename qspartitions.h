#ifndef QSPARTITIONS_H
#define QSPARTITIONS_H
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

int partition(vector<pair<int, char>>& arr, int p, int r);
int hoarsPartition(vector<pair<int, char>>& arr, int p, int r);

int randomPartition(vector<pair<int, char>>& arr, int p, int r);
void quickSort(vector<pair<int, char>>& arr,  int p, int r, int arg);


#endif
