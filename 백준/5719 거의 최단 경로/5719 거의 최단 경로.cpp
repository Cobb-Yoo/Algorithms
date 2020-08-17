#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

const int MAX = 500;
const int INF = 987654321;

int n,m;
vector<pair<int,int>> graph[MAX];
vector<pair<int,int>> trace[MAX];
bool visited[MAX][MAX];

vector<int> dijkstra(int s, int d){
	vector<int> distance(d, INF);
	distance[s] = 0;
	
	priority_queue<pair<int,int>> pq;
	pq.push({0,s});
	
	while(!pq.empty()){
		int cost = -pq.top().first;
		int curPosi = pq.top().second;
		pq.pop();
		
		if(distance[curPosi] < cost) continue;
		
		for(int i=0;i<graph[curPosi].size();i++){
			int next = graph[curPosi][i].first;
			int nextDistance = cost + graph[curPosi][i].second;
			
			if(graph[curPosi][i].second == -1) continue;
			
			if(distance[next] > nextDistance){
				distance[next] = nextDistance;
				pq.push({-nextDistance,next});
				
				trace[next].clear();
				trace[next].push_back({curPosi, nextDistance});
			}
			else if(distance[next] == nextDistance){
				trace[next].push_back({curPosi, nextDistance});
			}
		}
	}
	return distance;
}

void bfs(int destination){
	queue<int> q;
	q.push(destination);
	
	while(!q.empty()){
		int curPosi = q.front();
		q.pop();
		
		for(int i=0;i<trace[curPosi].size();i++){
			int next = trace[curPosi][i].first;
			
			if(visited[curPosi][next]) continue;
			
			for(int j=0;j<graph[next].size();j++){
				if(graph[next][j].first == curPosi) graph[next][j].second = -1;
			}
			
			q.push(next);
		}
	}
}

int main(){
	while(1){
		memset(visited,0,sizeof(visited));
		memset(trace,0,sizeof(trace));
		for(int i=0;i<MAX;i++) graph[i].clear();
		
		cin >> n >> m;
		if(n==0 && m==0) break;
		
		int s, d;
		cin >> s >> d;
		
		for(int i=0;i<m;i++){
			int s, d, cost;
			cin >> s >> d >> cost;
			
			graph[s].push_back({d,cost});
		}
		
		dijkstra(s,n);
		bfs(d);
		
		vector<int> result = dijkstra(s,n);
		
		if(result[d] == INF) cout << -1 << endl;
		else cout << result[d] << endl;
	}
}
