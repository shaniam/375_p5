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

int partition(vector<pair<int, char>>& arr, int p, int r){
	pair<int, char> last=arr[r];
	pair<int, char> other;
	int i = p-1;
	for (int j=p; j<=(r-1); j++){
		if(arr[j].first<=last.first){
			i++;
			other=arr[i];
			arr[i]=arr[j];
			arr[j]=other;
		}
	}
	other=arr[i+1];
	arr[i+1]=arr[r];
	arr[r]=other;
	return i+1;


	
}
int hoarsPartition(vector<pair<int, char>>& arr, int p, int r){
	pair<int, char> last=arr[p];
	int i = p-1;
	int j = r+1;
	pair<int, char> other;
	while( true ){
		do {
			j--;
		}
		while(!(arr[j].first<=last.first));
		do {
			i++;
		}
		while(!(arr[i].first>=last.first));
		if (i<j){
			other=arr[i];
			arr[i]=arr[j];
			arr[j]=other;
		}
		else{
		return j;
		}
	}
	//return j;
}

int randomPartition(vector<pair<int, char>>& arr, int p, int r){
	int i= rand() % r + p;
	pair<int, char> other = arr[i];
	arr[i]=arr[r];
	arr[r]=other;
	return partition(arr, p, r);

        
}
void quickSort(vector<pair<int, char>>& arr,  int p, int r, int arg){
	int q;
	if (p<r){
		if(arg==0){
			q=partition(arr ,p, r);
		}
		else if(arg==1){
			q=hoarsPartition(arr, p, r);
		}
		else if (arg==2){
			q=randomPartition(arr, p, r);
		}
		quickSort(arr, p, q-1, arg);
		quickSort(arr, q+1, r, arg);
	}
}
int main(){
	//vector<pair<int, int>> arr ={(1,2}};
	vector<pair<int, char>> arr={make_pair(4,'s'),make_pair(2,'s'),make_pair(2,'m'),make_pair(16,'s'),make_pair(13,'s')};
	quickSort(arr,0, 4, 2);
	for (auto x: arr){
		cerr << x.first << x.second << endl;
	}
}
