#include <iostream>
#define ll long long
using namespace std;

ll n;
ll arr[1500000];

int main(){
	cin >> n;
	
	arr[0]=0;
	arr[1]=1;
	
	for(ll i=2;i<1500000;i++){
		arr[i] = (arr[i-1] + arr[i-2])%1000000;
	}
	
	cout << arr[n%1500000] << endl;
	
}
