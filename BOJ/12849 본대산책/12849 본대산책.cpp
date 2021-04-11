#include <iostream>
using namespace std;

int arr[2][8];
const int mod = 1000000007;

int main(){	
	int n; cin >> n;
	
	arr[0][0] = 1;
	
	for(int i=0;i<n;i++){
		
		arr[1][0] = (arr[0][1] + arr[0][2])%mod;
		arr[1][1] = (arr[0][0] + arr[0][2] + arr[0][3])%mod;
		arr[1][2] = (arr[0][0] + arr[0][1] + arr[0][3]+ arr[0][4])%mod;
		arr[1][3] = (arr[0][1] + arr[0][2] + arr[0][4] + arr[0][5])%mod;
		arr[1][4] = (arr[0][2] + arr[0][3] + arr[0][5] + arr[0][6])%mod;
		arr[1][5] = (arr[0][3] + arr[0][4] + arr[0][7])%mod;
		arr[1][6] = (arr[0][4] + arr[0][7])%mod;
		arr[1][7] = (arr[0][5] + arr[0][6])%mod;
		
		for(int i=0;i<8;i++){
			arr[0][i] = arr[1][i];
		}
	}
	
	cout << arr[0][0];
}
