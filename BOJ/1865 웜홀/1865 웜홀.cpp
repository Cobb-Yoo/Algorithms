#include <iostream>
#include <vector>
using namespace std;

int tc,n,m,w;
const int MAX = 500;
vector<pair<int,int>> map[MAX+1];
int dis[MAX+1];
		

void solve(){
	dis[1] = 0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			int len = map[j].size();
			
			for(int k=0;k<len;k++){
				int next = map[j][k].first;
				int cost = map[j][k].second;
				
				if(dis[next] > dis[j]+cost){
					dis[next] = dis[j]+cost;
					if(i == n) {
						cout << "YES\n";
						return;
					}
				}
			}
		}
	}
	cout << "NO\n";
}

void init(){
	for(int i=0;i<MAX+1;i++) map[i].clear();
	for(int i=0;i<MAX+1;i++) dis[i] = 987654321;
	
	cin >> n >> m >> w;
}

int main(){
	cin >>tc;
	
	for(int T=0;T<tc;T++){
		init();
		
		for(int s,e,t,i=0;i<m;i++){
			cin >> s >> e >> t;
			
			map[s].push_back({e,t});
			map[e].push_back({s,t});
		}
		
		for(int s,e,t,i=0;i<w;i++){
			cin >> s >> e >> t;
			
			map[s].push_back({e,-t});
		}
		
		solve();
	}
}
