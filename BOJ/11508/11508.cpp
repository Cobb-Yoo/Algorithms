#include <bits/stdc++.h>
using namespace std;

int main(){
	int n; cin >> n;
	vector<int> v(n);
	for(int i=0;i<n;i++) cin >> v[i];
	
	sort(v.begin(), v.end(), greater<int>());
	
	int result = 0;
	for(int i=0;i<n;i++){
		if(i%3 == 2) continue;
		
		result += v[i];
	}
	
	cout << result << endl;
}
