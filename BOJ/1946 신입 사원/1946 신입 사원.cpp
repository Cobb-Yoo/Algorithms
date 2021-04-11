#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool cmp(pair<int,int> a, pair<int,int> b){
	return a.first < b.first;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t; cin >> t;
	
	while(t--){
		int n; cin >> n;
		int answer = n;
		
		vector<pair<int,int>> v;
		for(int i=0;i<n;i++){
			int a, b;
			cin >> a >> b;
			
			v.push_back({a,b});
		}
		
		sort(v.begin(), v.end(), cmp);
		int bound = v[0].second;
		
		for(int i=1;i<n;i++){
			if(v[i].second > bound) answer--;
			bound = min(bound, v[i].second);
		}
		
		cout << answer << endl;
	}
}
