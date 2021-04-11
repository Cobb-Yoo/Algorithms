#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int MAX = 800;
const int INF = 987654321;

int n,m;
vector<pair<int,int>> dataArr[MAX+1];

vector<int> djikstra(int startPoint, int endPoint){
	vector<int> dist(endPoint,INF);
	dist[startPoint] = 0;
	
	priority_queue<pair<int,int>> pq;
	pq.push(make_pair(0,startPoint));
	
	while(!pq.empty()){
		int cost = pq.top().first;
		int vertex = pq.top().second;
		pq.pop();
		
		if(dist[vertex] < cost) continue;
		
		for(int i=0;i< dataArr[vertex].size();i++){
			int next = dataArr[vertex][i].first;
			int nextDistance = cost + dataArr[vertex][i].second;
			
			if(nextDistance < dist[next]){
				dist[next] = nextDistance;
				pq.push(make_pair(nextDistance,next));
			}
		}
	}
	
	return dist;
}

int main(){
	cin >> n >> m;
	
	int a,b,c;
	for(int i=0;i<m;i++){
		cin >> a >> b >> c;
		dataArr[a].push_back(make_pair(b,c));
		dataArr[b].push_back(make_pair(a,c));
	}
	n++;
	
	int x,y;
	cin >> x >> y;
	
	vector<int> i = djikstra(1,n);
	vector<int> j = djikstra(x,n);
	vector<int> k = djikstra(y,n);
	
	
	int result = min(i[x]+j[y]+k[n-1], i[y]+k[x]+j[n-1]);
	
	if(result < 0 || INF <= result) cout << -1 << endl;
	else cout << result << endl;
}
