#include <iostream>
#include <cstdlib>
#include <vector>
#include <cmath>
#include "linear.h"

using namespace std;

void radixSort(vector<pair<int, char>> &vect, int d, int max){

  int k = 0, digit = 32 / d;

  k = pow(2.0, digit);

  for(int i = 1; max / i > 0; i *= k){
    countingSort(vect, k, vect.size(), i);
  }
}

void countingSort(vector<pair<int, char>> &a, int k, int n, int exp){
  vector<int> c(k, 0);
  vector<int> b(n);

  for(int j = 0; j < n; j++){
    c[(a[j].first / exp) % k] = c[(a[j].first / exp) % k] + 1;
  }
  for(int i = 1; i < k; i++){
    c[i] = c[i] + c[i - 1];
  }
  for(int j = n - 1; j >= 0; j--){
    b[c[(a[j].first / exp) % k] - 1] = a[j].first;
    c[(a[j].first / exp) % k] = c[(a[j].first / exp) % k] - 1;
  }

  for(int i = 0; i < n; i++){
    a[i].first = b[i];
  }
}

void pidgeonholeSort(vector<pair<int, char>> &vect, int k, int n){
  vector<int> c(k, 0);

  for(int j = 1; j < n; j++){
    c[vect[j].first] = c[vect[j].first] + 1;
  }
  int q = 1;
  for (int j = 1; j < k; j++){
    while(c[j] > 0){
      vect[q].first = j;
      c[j] = c[j] - 1;
      q = q + 1;
    }
  }
}

// int main(){
//
// vector<pair<int, char>> numberList;
//
// for(int i = 0; i < 10; i++){
//   numberList.push_back(make_pair(rand() % 10000000, 'a'));
// }
//
// radixSort(numberList, 1, 10000000);
//
// for(int i = 0; i < 10; i++){
//   cout << "I: " << i << " Num: " << numberList[i].first << endl;
// }
//
// return 0;
// }
