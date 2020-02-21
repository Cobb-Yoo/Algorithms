#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	int n;
	cin >> n;
	int MAX;
	
	int arr[n];
	int brr[n];
	
	for(int i=0;i<n;i++){
		cin >> arr[i];
	}
	
	brr[0] = arr[0];
	MAX = arr[0];
	
	for(int i=1;i<n;i++){
		brr[i] = max(brr[i-1] + arr[i],arr[i]);
		MAX = max(brr[i],MAX);
	}
	
	cout << MAX << endl;
}
