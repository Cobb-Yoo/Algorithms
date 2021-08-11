#include <bits/stdc++.h>
using namespace std;

int n;

int main(){
	cin >> n;
	vector<int> v(n);
	
	for(int i=0;i<n;i++){
		cin >> v[i];
	}
	
	sort(v.begin(), v.end(), greater<int>());
	
	int cnt=2;
	int answer=0;
	
	for(int i=0;i<n;i++){
		answer = max(answer, v[i]+cnt);
		cnt++;
	}
	
	cout << answer;
}
