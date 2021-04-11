#include <iostream>
#include <cmath>
using namespace std;

void check(int x, int& count){
	int n = sqrt(x);
	
	if(x == 1) return;
	
	for(int i=2;i <= n;i++){
		if(x % i == 0) {
			return;
		}
	}
	
	count++;
}

int main(){
	int arr[100]={0};
	int n, count;
	
	cin >> n;
	
	for(int i=0;i<n;i++){// scan
		cin >> arr[i];
	}
	
	for(int i=0;i<n;i++){
		check(arr[i], count);
	}
	
	cout << count << endl;
}
