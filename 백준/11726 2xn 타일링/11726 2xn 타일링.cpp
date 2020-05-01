#include <iostream>
using namespace std;

const int MAX = 1000;

int arr[MAX+1];

void init(){
	arr[1] = 1;
	arr[2] = 2;
	
	for(int i=3;i<=MAX;i++){
		arr[i] = (arr[i-1] + arr[i-2])%10007;
	}
}

int main(){
	int n;
	cin >> n;
	init();
	
	cout << arr[n] << endl;
}
