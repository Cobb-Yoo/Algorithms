#include <bits/stdc++.h>
using namespace std;

vector<int> v;

int main(){
	int n; cin >> n;
	
	while(n){
		v.push_back(n%10);
		n /= 10;
	}
	
	int len = v.size();
	
	for(int i=1;i<len;i++){
		int a = 1;
		int b = 1;
		
		for(int j=0;j<i;j++) a *= v[j];
		for(int j=i;j<len;j++) b *= v[j];
		
		if(a == b) {
			cout << "YES\n";
			exit(0);
		}
	}
	
	cout << "NO\n";
}
