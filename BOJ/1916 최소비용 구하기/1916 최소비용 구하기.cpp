#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n,m;
vector<vector<int>> v;
int inf = 0xfffffff;

void dijkstra(int start, int end){
	vector<bool> visited(n+1, false);
	vector<int> dist(n+1, inf);
	
	for(int i=1;i<=n;i++) dist[i] = v[start][i];
	
	int cnt = n;
	int vnear = start;
	visited[start] = 1;
	
	while(cnt--){
		int min_dist = inf;
		for(int i=1;i<=n;i++){
			if(!visited[i] && min_dist>dist[i]){
				vnear = i;
				min_dist = dist[i];
			}
		}
		
		for(int i=1;i<=n;i++){
			if(visited[i] || v[vnear][i] == inf) continue;
			
			if(dist[vnear] + v[vnear][i] < dist[i]) dist[i] = dist[vnear] + v[vnear][i];
		}
		visited[vnear] = 1;
	}
	
	cout << dist[end] << endl;
}

int main(){	
	cin >> n >> m;
	
	v = vector<vector<int>> (n+1, vector<int> (n+1,inf));
	
	int start, end, cost;
	
	for(int i=0;i<m;i++){
		cin >> start >> end >> cost;
		v[start][end] = min(v[start][end], cost);
	}
	
	cin >> start >> end;
	dijkstra(start, end);
}
