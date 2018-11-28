#include "mergetest.h"

using namespace std;

//Globals

//Function declarations
void merge( vector< pair<int,char> > &A, int low, int mid, int high);
void mergeSort(vector< pair<int, char> > &A, int p, int r);
void tripartMerge(vector< pair<int, char> > &A, int low, int mid, int high, int size);
void tripartMSort(vector< pair<int, char> > &A, int p, int r);


int main(){
	//vector<pair<int, int>> arr ={(1,2}};
	vector<pair<int, char>> arr={make_pair(4,'s'),make_pair(2,'s'),make_pair(2,'m'),make_pair(16,'s'),make_pair(13,'s')};
	/*
	mergeSort(arr, 0, 5);
	for (auto x: arr){
		cerr << x.first << x.second << endl;
	}
	*/
	vector<pair<int, char>> arr2={make_pair(4,'s'),make_pair(2,'s'),make_pair(2,'m'),make_pair(16,'s'),make_pair(13,'s')};
	tripartMSort(arr2, 0, 5);
	for (auto x: arr2){
		cerr << x.first << x.second << endl;
	}
}

//high needs to be total size of the array, not the largest index
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
				i++;
			} else {
				A[k] = R[j];
				j++;
			}
		} else if(R[j].first != 65536){
			A[k] = R[j];
			j++;
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

void tripartMerge(vector< pair<int, char> > &A, int low, int mid, int high, int size ){

	int left = mid-low;
	int center = high-mid;
	int right = size-high;
	vector< pair<int, char> > L,C,R;
	int i=0;
	for(; i<left; i++){
		L.push_back(A[low+i]);
	}
	for(i=0; i<center; i++){
		C.push_back(A[mid+i]);
	}
	for(i=0; i<right; i++){
		R.push_back(A[high+i]);
	}
	pair<int, char> sentinel = make_pair(65536,'!');
	L.push_back(sentinel);
	R.push_back(sentinel);
	i = 0;
	int j = 0;
	int k = 0;
	for(int l = low; l<high; l++){

		if(L[i].first != 65536){
			if( (L[i].first <= C[j].first) && (L[i].first <= R[k].first) ){
					A[l] = L[i];
					i++;
			} else {
				if(C[j].first <= R[k].first){
					A[l] = C[j];
					j++;
				}else{
					A[l] = R[k];
					k++;
				}
			}

		} else if(C[j].first != 65536){

			if(C[j].first <= R[k].first){
				A[l] = C[j];
				j++;
			}else{
				A[l] = R[k];
				k++;
			}

		} else if(R[k].first != 65536){
			A[l] = R[k];
			k++;
		}

	}

	return;
}

void tripartMSort(vector< pair<int, char> > &A, int p, int r){

	if( r-p>1 ) {

		float third = (float)(p+r) / (float)3;
		int q = ceil(third);
		int t = floor(third*2);
		tripartMSort(A,p,q);
		tripartMSort(A,q+1,t);
		tripartMSort(A,t+1,r);
		tripartMerge(A,p,q,t,r);

	}

	return;
}