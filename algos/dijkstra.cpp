#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int inf = 987654321;

int dis[50];

int main(){
	int n,m;// 간선의 수;
	cin >> n >> m;
	
	vector<pair<int,int>> map[n+1];
	fill(dis,dis+n+1,inf);
	
	for(int i=0;i<m;i++){
		int a,b,c;
		cin >> a >> b >> c;
		
		map[a].push_back({b,c});
		map[b].push_back({a,c});
	}
	
	int start, end;
	cin >> start >> end;
	
	priority_queue<pair<int,int>> pq; // <cost, nodenumber>;
	pq.push({0, start});
	
	dis[start] = 0;
	
	while(!pq.empty()){
		int cost = -pq.top().first;
		int nowPosi = pq.top().second;
		
		pq.pop();
		
		for(int i=0;i<map[nowPosi].size();i++){
			int nextPosi = map[nowPosi][i].first;
			int nextCost = map[nowPosi][i].second;
			
			if(dis[nextPosi] > dis[nowPosi]+nextCost){
				dis[nextPosi] = dis[nowPosi]+nextCost;
				pq.push({-dis[nextPosi],nextPosi});
			}
		}
	}
	
	cout << dis[end] << endl;
}
