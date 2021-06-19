#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<int,string> a, pair<int,string> b){
	return a.first > b.first;
}

int main(){
	int t; cin >> t;
	
	while(t--){
		vector<pair<int,string>> v;
		int n; cin >> n;
		
		int price;
		string name;
		for(int i=0;i<n;i++){
			cin >> price >> name;
			v.push_back({price, name});
		}
		
		sort(v.begin(), v.end(), cmp);
		
		cout << v[0].second << endl;
	}
}
