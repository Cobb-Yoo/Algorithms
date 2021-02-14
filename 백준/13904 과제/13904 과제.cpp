#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>> v;
int arr[1001];

bool cmp(pair<int,int> a, pair<int,int> b){
	return a.second > b.second;
}

int main(){
	int n; cin >> n;
	
	for(int a,b,i=0;i<n;i++){
		cin >> a >> b;
		v.push_back({a,b});
	}
	
	sort(v.begin(), v.end(), cmp);
	
	for(int i=0;i<n;i++){
		if(arr[v[i].first] == 0){
			arr[v[i].first] = v[i].second;
			continue;
		}
		int idx = v[i].first-1;
		
		while(idx >= 0){
			if(arr[idx] == 0){
				arr[idx] = v[i].second;
				break;
			}
			idx--;
		}
	}
	
	int ans = 0;
	for(int i=1;i<=1000;i++) ans += arr[i];
	
	cout << ans;
}
