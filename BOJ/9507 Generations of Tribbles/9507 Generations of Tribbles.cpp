#include <iostream>
using namespace std;

long long arr[69];

void init(){
	arr[0] = 1;
	arr[1] = 1;
	arr[2] = 2;
	arr[3] = 4;
	
	for(int i=4;i<69;i++){
		arr[i] = arr[i-1] + arr[i-2] + arr[i-3] + arr[i-4];
	}
}

int main(){
	int t;
	cin >> t;
	
	init();
	
	for(int i=0;i<t;i++){
		int tmp;
		cin >> tmp;
		
		cout << arr[tmp] << endl;
	}
}
