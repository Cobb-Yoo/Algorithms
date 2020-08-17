#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n,m;
int dis[20001];
int cnt=0;
vector<int> v[20001];
int mx=-1;

void dijkstra(int start){
	queue<int> q;
	q.push(start);
	
	while(!q.empty()){
		int x = q.front();
		q.pop();
		
		for(int i=0;i<v[x].size();i++){
			if(!dis[v[x][i]]){
				dis[v[x][i]] = dis[x]+1;
				q.push(v[x][i]);
			}
		}
	}
}

int main(){
	cin >> n >> m;
	
	for(int i=0;i<m;i++){
		int a,b;
		cin >> a >> b;
		
		v[a].push_back(b);
		v[b].push_back(a);
	}
	
	dijkstra(1);
	
	int location;
	for(int i=2;i<=n;i++) {
		if(dis[i] > mx){
			mx = dis[i];
			location = i;
		}
	}
	
	for(int i=2;i<=n;i++){
		if(dis[i] == mx) cnt++;
	}
	
	cout << location << " " << mx << " " << cnt << endl;
}
