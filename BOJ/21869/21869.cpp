#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cout.tie(0);
	
	int n; cin >> n;
	
	if(n == 1){
		cout << "1\n1 1"<< endl;
	}
	else {
		cout << (n-1)*2 << endl;
		for(int i=2;i<=n;i++){
			cout << "1 " << i << "\n";
		}
		for(int i=2;i<=n;i++){
			cout << n << " " << i << "\n";
		}
	}
}
