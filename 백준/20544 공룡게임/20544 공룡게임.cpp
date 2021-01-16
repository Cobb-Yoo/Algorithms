#include <iostream>
#include <cmath>
#define ll long long
using namespace std;

const int mod = 1000000007;
ll arr[1000+1];
ll brr[1000+1];

int main(){
	int n; cin >> n;
	
	arr[2] = 1;
	arr[3] = 4;
	arr[4] = 10;
	
	brr[1] = 2;
	brr[2] = 4;
	brr[3] = 7;
	brr[4] = 13;
	
	for(int i=5;i<=n;i++){
		brr[i] = (brr[i-3] + brr[i-2] + brr[i-1])%mod;
	}
	
	for(int i=5;i<=n;i++){
		arr[i] = (arr[i-1] + arr[i-3]*3 + arr[i-2]*2 + brr[i-3]+brr[i-4]*2)%mod;
	}
	
	cout << arr[n] << endl;
}
