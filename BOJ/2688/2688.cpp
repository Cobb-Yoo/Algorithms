#include <bits/stdc++.h>
using namespace std;

int n;
long long arr[65][10];

void init(){
	for(int i=0;i<10;i++){
		arr[1][i] = i+1;
	}
	
	for(int i=2;i<65;i++){
		arr[i][0] = 1;
		for(int j=1;j<10;j++){
			arr[i][j] = arr[i-1][j] + arr[i][j-1];
		}
	}
}

int main(){
	int t; cin >> t;
	init();
	
	while(t--){
		cin >> n;
		
		cout << arr[n][9] << endl;
	}
}
