#include <bits/stdc++.h>
using namespace std;

const int Max = 2000;
int n,m;
vector<int> graph[Max];
bool visited[Max];

void dfs(int idx, int cnt){
	visited[idx] = 1;
	
	if(cnt == 4){
		cout << 1;
		exit(0);
	}
	
	for(int i=0;i<graph[idx].size();i++){
		if(!visited[graph[idx][i]]){
			dfs(graph[idx][i], cnt+1);
		}
	}
	
	visited[idx] = 0;
}

int main(){
	cin >> n >> m;
	
	for(int i=0;i<m;i++){
		int a,b;
		cin >> a >> b;
		
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	
	for(int i=0;i<n;i++){
		dfs(i,0);
	}
	
	cout << 0;
}
