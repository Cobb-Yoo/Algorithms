#include <bits/stdc++.h>
#define ll long long
using namespace std;

vector<int> v;

void solve(){
	sort(v.begin(), v.end());
	ll min = LLONG_MAX;
	int y,x;
	int l=0, r = v.size()-1;
	
	while(l < r){
		ll sum = v[l]+v[r];
		
		if(llabs(sum) < min){
			min = llabs(sum);
			y = l;
			x = r;
		}
		
		if(sum < 0) l++;
		else r--;
	}
	
	cout << v[y] << " " << v[x];
}

int main(){
	int n; cin >> n;
	
	for(int tmp,i=0;i<n;i++){
		cin >> tmp;
		
		v.push_back(tmp);
	}
	
	solve();
}
