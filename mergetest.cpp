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

//Globals

//Function declarations
void merge( vector< pair<int,char> > &A, int p, int q, int r);
void mergeSort(vector< pair<int, char> > &A, int p, int r);

int main(){
	//vector<pair<int, int>> arr ={(1,2}};
	vector<pair<int, char>> arr={make_pair(4,'s'),make_pair(2,'s'),make_pair(2,'m'),make_pair(16,'s'),make_pair(13,'s')};
	mergeSort(arr, 0, 5);
	for (auto x: arr){
		cerr << x.first << x.second << endl;
	}
}

void merge( vector< pair<int,char> > &A, int low, int mid, int high){

	int left = mid-low;
	int right = high-mid;
	vector<pair<int, char>> L, R;
	int i = 0;
	for(; i<left; i++){
		L.push_back(A[low+i]);
	}
	for(i=0; i<right; i++){
		R.push_back(A[mid+i]);
	}
	pair<int, char> sentinel = make_pair(65536,'!');
	L.push_back(sentinel);
	R.push_back(sentinel);
	i = 0;
	int j = 0;
	for(int k = low; k<high; k++){
		if( L[i].first != 65536 ){
			if(  L[i].first <= R[j].first ){
				A[k] = L[i];
				i+=1;
			} else {
				A[k] = R[j];
				j+=1;
			}
		} else if(R[j].first != 65536){
			A[k] = R[j];
			j+=1;
		}

	}
	return;
}

void mergeSort(vector< pair<int, char> > &A, int p, int r){

	if(p<r){
		int q = floor( (p+r)/2 );
		mergeSort(A,p,q);
		mergeSort(A,q+1,r);
		merge(A,p,q,r);
	}
	return;
}