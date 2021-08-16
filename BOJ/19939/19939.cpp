#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,k;
	cin >> n >> k;
	
	if(n<k*(k+1)/2){
		cout << -1;
		exit(0);
	}
	
	if((n-k*(k+1)/2)%k == 0) cout << k-1;
	else cout << k;
	
}
