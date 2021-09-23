#include <bits/stdc++.h>
using namespace std;

const int Max = 1000;
const int Inf = 987654321;
int trace[Max+1];
int n,m;
vector<pair<int,int>> Map[Max+1];

vector<int> dijkstra(int start, int vertex){
	vector<int> distance(vertex, Inf);
	distance[start] = 0;
	
	priority_queue<pair<int,int> vector<pair<int,int>>, greater<int,int>>> pq;
	pq.push({0, start});
	
	while(!pq.empty()){
		int cost = pq.top().first;
		int cur = pq.top().second;
		int len = Map[cur].size();
		pq.pop();

 		if (distance[cur] < cost) continue;

		for(int i=0;i<len;i++){
			int neighbor = Map[cur][i].first;
			int neighborDistance = cost + Map[cur][i].second;

			if (distance[neighbor] > neighborDistance){
				distance[neighbor] = neighborDistance;
				trace[neighbor] = cur;
				pq.push({ neighborDistance, neighbor });
			}
		}
	}

	return distance;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	
	n++;
	
	int a, b, c;
	for(int i=0;i<m;i++){
		cin >> a >> b >> c;
		
		Map[a].push_back({b,c});
	}
	
	int start, terminal;
	cin >> start >> terminal;
	
	vector<int> result = dijkstra(start, n);
	
	cout << result[terminal] << endl;
	
	vector<int> route;
	int node = terminal;
	
	while(node){
		route.push_back(node);
		node = trace[node];
	}
	
	cout << route.size() << endl;
	
	for(int i=route.size()-1;i>=0;i--){
		cout << route[i] << " ";
	}
}
