#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int INF = 987654321;
const int MAX = 1000;
int n,m,p;
vector<pair<int,int>> graph[MAX+1];

vector<int> dijstra(int start, int vertex){
	vector<int> distance(vertex, INF);
	distance[start] = 0;
	
	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
	pq.push({0, start});
	
	while(!pq.empty()){
		int cost = pq.top().first;
		int cur = pq.top().second;
		pq.pop();
		
		if(distance[cur] < cost) continue;
		
		for(int i=0;i<graph[cur].size();i++){
			int neighbor = graph[cur][i].first;
			int neighborDistance = cost + graph[cur][i].second;
			
			if(distance[neighbor] > neighborDistance){
				distance[neighbor] = neighborDistance;
				pq.push({neighborDistance, neighbor});
			}
		}
	}
	
	return distance;
}

int main(){
	cin >> n >> m >> p;
	
	for(int i=0;i<m;i++){
		int begin, end, cost;
		cin >> begin >> end >> cost;
		
		graph[begin].push_back({end, cost});
	}
	
	int result = -1;
	for(int i=1;i<=n;i++){
		vector<int> tmp = dijstra(i, n+1);
		vector<int> tmp2 = dijstra(p, n+1);
		
		if(tmp[p]+tmp2[i] >= INF || tmp[p]+tmp2[i] < 0) continue;
		
		result = max(result, tmp[p]+tmp2[i]);
	}
	
	cout << result << endl;
}
