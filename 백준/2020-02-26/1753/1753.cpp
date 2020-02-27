#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MAX = 20000 + 1;
const int INF = 987654321;

int V,E,startPoint;
int a,b,W;
vector<pair<int,int>> dArr[MAX+1];

vector<int> f(){
	vector<int> dist(V, INF);
	dist[startPoint] = 0;
	
	priority_queue<pair<int,int>> pq;
	pq.push(make_pair(0,startPoint));
	
	while(!pq.empty()){
		int cost  = -pq.top().first;
		int curVertex  = pq.top().second;
		pq.pop();
		
		if(dist[curVertex] < cost) continue;
		
		for(int i=0;i< dArr[curVertex].size();i++){
			int next = dArr[curVertex][i].first;
			int nextDistance = cost + dArr[curVertex][i].second;
			
			if(nextDistance < dist[next]){
				dist[next] = nextDistance;
				pq.push(make_pair(-nextDistance,next));
			}
		}
	}
	return dist;
}

int main(){
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	
	cin >> V >> E >> startPoint;
	
	V++;
	
	for(int i=0;i<E;i++){
		cin >> a >> b >> W;
		dArr[a].push_back(make_pair(b,W));
	}
	
	vector<int> result = f();
	
	for(int i=1;i<V;i++){
		if(result[i] == INF) cout << "INF\n";
		else cout << result[i] << "\n";
	}
}
