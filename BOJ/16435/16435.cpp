#include <bits/stdc++.h>
using namespace std;

int main(){
	int n, len;
	cin >> n >> len;
	vector<int> v(n);
	
	for(int i=0;i<n;i++){
		cin >> v[i];
	}
	
	sort(v.begin(), v.end());
	
	for(int& i : v) {
		if(len >= i) len++;
	}
	
	cout << len;
}
