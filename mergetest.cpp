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
	mergeSort(arr, 0, 4);
	for (auto x: arr){
		cerr << x.first << x.second << endl;
	}
}

void merge( vector< pair<int,char> > &A, int p, int q, int r){

	int m = q-p+1;
	int n = r-q;
	vector<pair<int, char>> L, R;
	for(int i=0; i<m-1; i++){
		L.push_back(A[p+i-1]);
	}
	for(int i=0; i<n-1; i++){
		R.push_back(A[q+i]);
	}
	pair<int, char> sentinel = make_pair(-1,'!');
	L.push_back(sentinel);
	R.push_back(sentinel);
	int i = 1;
	int j = 1;
	for(int k = p; k<r; k++){
		if( (L[i].first != -1) && (L[i].first <= R[j].first) ){
			A[k] = L[i];
			i+=1;
		} else {
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