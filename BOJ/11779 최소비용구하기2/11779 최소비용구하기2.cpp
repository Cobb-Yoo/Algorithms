#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int MAX = 1000;
int n,m;
int dist[MAX+1];
int p[MAX+1];
int station, terminal;
vector<pair<int,int>> v[MAX+1];
int arr[MAX+1];

void solve(){
	for(int i=1;i<=n;i++) dist[i] = 987654321;
	queue<pair<int,int>> q;
	queue<int> tmp;
	tmp.push(station);
	q.push({station, 0});
	dist[station] = 0;
	
	while(!q.empty()){
		int city = q.front().first;
		int distance = q.front().second;
		q.pop();
		
		int len = v[city].size();
		for(int i=0;i<len;i++){
			int nextCity = v[city][i].first;
			int nextDistance = distance + v[city][i].second;
			
			if(dist[nextCity] > nextDistance){
				dist[nextCity] = nextDistance;
				q.push({nextCity, nextDistance});
				arr[nextCity] = city;
			}
		}
	}
}

int main(){
	cin >> n >> m;
	
	for(int a,b,c,i=0;i<m;i++){
		cin >> a >> b >> c;
		
		v[a].push_back({b,c});
	}
	
	cin >> station >> terminal;
	
	solve();
	
	cout << dist[terminal] << endl;
	
	vector<int> route;
	int node = terminal;
	
	while(node){
		route.push_back(node);
		node = arr[node];
	}
	int len = route.size();
	cout << len << endl;
	for(int i=len-1;i>=0;i--){
		cout << route[i] << " ";
	}
}
