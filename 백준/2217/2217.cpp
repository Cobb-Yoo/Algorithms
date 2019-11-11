#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	int n;
	cin >> n;
	
	int arr[n];
	
	for(int i=0;i<n;i++){
		cin >> arr[i];
	}
	
	sort(arr,arr+n);
	
	int max=0;
	for(int i=0, tmp_n = n;i<n;i++,tmp_n--){
		if(max < arr[i] * tmp_n) max = arr[i]* tmp_n;
	}
	
	cout << max << endl;
}
