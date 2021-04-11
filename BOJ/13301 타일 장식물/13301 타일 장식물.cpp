#include <iostream>
#define ll long long 
using namespace std;

const int MAX = 80;
ll arr[MAX+1];

int main(){
	arr[1] = 1;
	arr[2] = 1;
	
	ll n;
	cin >> n;
	
	for(ll i=3;i<=n;i++){
		arr[i] = arr[i-2]+arr[i-1];
	}
	
	cout << arr[n]*4 + arr[n-1]*2 << endl;
}
