#include <bits/stdc++.h>
using namespace std;

int main(){
	int n; cin >> n;
	vector<int> v(n);
	
	for(int i=0;i<n;i++){
		cin >> v[i];
	}
	
	sort(v.begin(), v.end());
	
	long long answer = 0;
	for(int i=0;i<n;i++){
		answer += abs(i+1-v[i]);
	}
	
	cout << answer;
}
