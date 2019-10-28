#include <iostream>
using namespace std;

int main(){
	int n;
	cin >> n;
	
	int arr[41][2]={0};
	
	arr[0][0] = 1;
	arr[0][1] = 0;
	
	arr[1][0] = 0;
	arr[1][1] = 1;
	
	for(int i=2;i<41;i++){
		arr[i][0] = arr[i-1][0] + arr[i-2][0];
		arr[i][1] = arr[i-1][1] + arr[i-2][1];
	}
	
	for(int i=0;i<n;i++){
		int t;
		cin >> t;
		
		cout << arr[t][0] << ' ' << arr[t][1] << endl;
	}
}
