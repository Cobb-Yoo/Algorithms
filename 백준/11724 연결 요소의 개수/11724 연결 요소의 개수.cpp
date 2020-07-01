#include <iostream> 
#include <vector>
using namespace std;

bool visited[4001];
vector<int> graph[4001];
int n,m;

void dfs(int n){
	visited[n] = 1;
	
	for(int i=0;i<graph[n].size();i++){
		int next = graph[n][i];
		if(!visited[next]) dfs(next);
	}
}

int main(){
	cin >> n >> m;
	
	for(int i=0;i<m;i++){
		int u,v;
		cin >> u >> v;
		
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	
	int cnt = 0;
	for(int i=1;i<=n;i++){
		if(!visited[i]){
			dfs(i);
			cnt++;
		}
	}
	
	cout << cnt << endl;
}
