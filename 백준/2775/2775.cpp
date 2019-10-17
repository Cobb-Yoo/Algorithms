#include <iostream>
using namespace std;

void init(int arr[][15]){
	for(int i=1;i<15;i++){
		arr[0][i] = i;
	}
	for(int i=1;i<15;i++){//1호실 초기화 
		arr[i][1] = 1;
	}
	
	for(int i=2;i<15;i++){
		for(int j=1;j<15;j++){
			arr[j][i] = arr[j][i-1] + arr[j-1][i];
		}
	}
}

int main(){
	int t,k,n;
	int arr[15][15];
	
	init(arr);
	
	cin >> t;
	
	for(int i=0;i<t;i++){
		cin >> k;
		cin >> n;
		
		cout << arr[k][n] << endl;
	}
}
