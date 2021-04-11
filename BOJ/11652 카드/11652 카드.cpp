#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#define ll long long
using namespace std;

map<ll, int> m;
vector<pair<ll,int>> v;
	
bool cmp(pair<ll,int> a, pair<ll,int> b){
	if(a.second == b.second) return a.first < b.first;
	return a.second > b.second;
}

int main(){

	int n; cin >> n;
	
	for(int i=0;i<n;i++){
		ll a; cin >> a;
		m[a]++;
	}
	
	copy(m.begin(), m.end(), back_inserter(v));
	sort(v.begin(), v.end(), cmp);
	
	cout << v[0].first << endl;
}
