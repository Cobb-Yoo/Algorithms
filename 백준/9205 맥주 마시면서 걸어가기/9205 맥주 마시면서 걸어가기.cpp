#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

vector<int> graph[101];
bool visited[101];

int distance(pair<int,int> a, pair<int,int> b){
	return abs(a.first-b.first) + abs(a.second-b.second);
}

void dfs(int idx){
	visited[idx] = 1;
	
	for(int i=0;i<graph[idx].size();i++){
		int next = graph[idx][i];
		if(!visited[next]){
			dfs(next);
		}
	}
}

int main(){
	int t; cin >> t;
	
	while(t--){
		for(int i=0;i<101;i++) graph[i].clear();
		memset(visited,0,sizeof(visited));
		
		int n; cin >> n;
		
		vector<pair<int,int>> v;
		for(int i=0;i<n+2;i++){
			int a,b;
			cin >> a >> b;
			
			v.push_back({a,b});
		}
		
		for(int i=0;i<n+2;i++){
			for(int j=i+1;j<n+2;j++){
				if(distance(v[i], v[j]) <= 1000){
					graph[i].push_back(j);
					graph[j].push_back(i);
				}
			}
		}
		
		dfs(0);
		
		if(visited[n+1]) cout << "happy\n";
		else cout << "sad\n";
	}
}
