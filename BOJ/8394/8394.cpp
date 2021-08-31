#include <bits/stdc++.h>
using namespace std;
int n;

const int Max = 10000001;
short arr[Max];

void solve(){
	arr[1] = 1;
	arr[2] = 2;
	arr[3] = 3;
	
	for(int i=4;i<=n;i++){
		arr[i] = (arr[i-1]+arr[i-2])%10;
	}
	
	cout << arr[n] << endl;
}

int main(){
	cin >> n;
	
	solve();
}
