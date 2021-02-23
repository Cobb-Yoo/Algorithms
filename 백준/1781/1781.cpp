#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>> v;

int main(){
	int n; cin >> n;
	
	for(int a,b,i=0;i<n;i++){
		cin >> a >> b;
		
		v.push_back({a-1,b});
	}
	
	sort(v.begin(), v.end());
	
	int cnt = 0;
	int idx = n-1;
	priority_queue<int> pq;
	
	for(int i=n-1;i>=0;i--){
		for(;idx >= 0 && v[idx].first == i;idx--) pq.push(v[idx].second);
		
		if(!pq.empty()){
			cnt += pq.top();
			pq.pop();
		}
	}
	
	cout << cnt << endl;
}
