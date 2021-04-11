#include <iostream>
#define MAX 10000
using namespace std;

int main(){
	int t;
	cin >> t;
	int arr[MAX];
	
	arr[1] = arr[2] = arr[3] = 1;
	arr[4] = 2;
	arr[5] = 2;
	
	for(int i=6;i<MAX;i++){
		arr[i] = arr[i-1] + arr[i-5];
	}
	
	for(int i=0;i<t;i++){
		int n;
		cin >> n;
		cout << arr[n] << endl;
	}
}
