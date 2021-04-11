#include <bits/stdc++.h>
using namespace std;

int n, m;
bool visited[1001];
vector<pair<int,int>> v;

bool cmp(pair<int,int> a, pair<int,int> b){
	if(!(a.second == b.second)) return a.second < b.second;
	return a.first < b.first;
}

int main(){
	int t; cin >> t;
	
	while(t--){
		memset(visited, 0, sizeof(visited));
		v.clear();
		
		cin >> n >> m;
		
		for(int a,b,i=0;i<m;i++){
			cin >> a >> b;
			
			v.push_back({a,b});
		}
		
		sort(v.begin(), v.end(), cmp);
		
		int cnt = 0;
		for(int i=0;i<m;i++){
			for(int j=v[i].first;j<=v[i].second;j++){
				if(!visited[j]){
					cnt++;
					visited[j] = 1;
					break;
				}
			}
		}
		
		cout << cnt << endl;
	}
}
