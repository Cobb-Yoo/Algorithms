#include <iostream>
#define ll long long
using namespace std;

int d,k;
int arr[31];

void init(){
	arr[0] = 0;
	arr[1] = 1;
	
	for(int i=2;i<31;i++){
		arr[i] = arr[i-1] + arr[i-2];
	}
	
	int a = arr[d-2];
	int b = arr[d-1];
	
	for(int i=1;i<=100000;i++){
		for(int j=i;j<=100000;j++){
			if(a*i+b*j == k){
				cout << i << endl;
				cout << j << endl;
				return;
			}
		}
	}
}

int main(){
	cin >> d >> k;
	
	init();
}
