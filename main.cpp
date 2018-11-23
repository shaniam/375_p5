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
void quickSort(vector<pair<int, char>>& arr,  int p, int r){
	int q;
	if (p<r){
		q=partition(arr ,p, r);
		quickSort(arr, p, q-1);
		quickSort(arr, q+1, r);
	}
}
int main(){
	//vector<pair<int, int>> arr ={(1,2}};
	vector<pair<int, char>> arr={make_pair(4,'s'),make_pair(2,'s'),make_pair(2,'m'),make_pair(16,'s'),make_pair(13,'s')};
	quickSort(arr,0, 4);
	for (auto x: arr){
		cerr << x.first << x.second << endl;
	}
}
