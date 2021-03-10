#include <bits/stdc++.h>
using namespace std;

int main(){
	vector<int> v;
	int n; cin >> n;
	
	for(int tmp,i=0;i<n;i++){
		cin >> tmp;
		v.push_back(tmp);
	}
	
	sort(v.begin(), v.end(), greater<int>());
	long long result=0;
	
	for(int i=1;i<=n;i++){
		int tmp = v[i-1] - (i-1);
		if(tmp > 0) result += tmp;
	}
	
	cout << result;
}
