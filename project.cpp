#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

vector<int> LSDradixSort(vector<int> vect, int d);
vector<int> MSDradixSort(vector<int> vect, int d);
void pidgeonholeSort(vector<int> &vect, int k, int n);
vector<int> countingSort(vector<int> a, int k, int n);

int main(){

  vector<int> numberList;

  for(int i = 0; i < 100; i++){
    numberList.push_back(rand() % 100);
  }

  vector<int> b = MSDradixSort(numberList, 100);

  for(int i = 0; i < 100; i++){
    cout << "I: " << i << " Num: " << b[i] << endl;
  }

  return 0;
}

vector<int> LSDradixSort(vector<int> vect, int d){
  vector<int> retVal(vect.size(), 0);
  for(int i = 1; i < d; i++){
    retVal = countingSort(vect, d, vect.size());
  }

  return retVal;
}

vector<int> MSDradixSort(vector<int> vect, int d){
  vector<int> retVal(vect.size(), 0);
  for(int i = d; i >= 1; i--){
    retVal = countingSort(vect, d, vect.size());
  }

  return retVal;
}

vector<int> countingSort(vector<int> a, int k, int n){
  vector<int> c(k, 0);
  vector<int> b(k, 0);

  for(int i = 0; i < k; i++){
    c[i] = 0;
  }
  for(int j = 1; j < n; j++){
    c[a[j]] = c[a[j]] + 1;
  }
  for(int i = 1; i < k; i++){
    c[i] = c[i] + c[i - 1];
  }
  for(int j = n; j >= 1; j--){
    b[c[a[j]]] = a[j];
    c[a[j]] = c[a[j]] - 1;
  }

  return b;
}

void pidgeonholeSort(vector<int> &vect, int k, int n){
  vector<int> c(k, 0);

  for(int i = 0; i < k; i++){
    c[i] = 0;
  }
  for(int j = 0; j < n; j++){
    c[vect[j]] = c[vect[j]] + 1;
  }
  int q = 0;
  for (int j = 0; j < k; j++){
    while(c[j] > 0){
      vect[q] = j;
      c[j] = c[j] - 1;
      q = q + 1;
    }
  }
}
