#ifndef LINEAR_H
#define LINEAR_H

#include <vector>

using namespace std;

void radixSort(vector<pair<int, char> > &vect, int d, int max);
void pidgeonholeSort(vector<pair<int, char> > &vect, int k, int n);
void countingSort(vector<pair<int, char> > &a, int k, int n, int exp);

#endif
