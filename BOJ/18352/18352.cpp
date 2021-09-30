#include <bits/stdc++.h>
using namespace std;

int n; // 도시의 개수 
int m; // 도로의 개수 
int k; // 거리 정보  
int x; // 출발 도시의 번호 

const int Inf = 987654321;
const int Max = 1000000;
vector<pair<int,int>> graph[Max];
priority_queue<int> answer;

void solve(){
	queue<pair<int,int>> q;
	q.push({x,0});
	
	while(!q.empty()){
		int now = q.front().first;
		int nowCost = q.front().first;
		q.pop();
		
		int len = graph[now].size();
		
		for(int i=0;i<len;i++){
			neighbor = graph[now][i].first;
			neighborCost = graph[now][i].second;
			
			if(neighborCost > nowCost+1){
				neighborCost = nowCost+1;
			}
			
			q.push({neighbor, neighborCost});
		}
	}
}

int main(){
	cin >> n >> m >> k >> x;
	int a,b;
	
	for(int i=0;i<m;i++){
		cin >> a >> b;
		
		graph[a].push(b);
	}
	
	solve();
}
