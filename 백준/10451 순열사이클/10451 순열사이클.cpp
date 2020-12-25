#include <iostream>
#include <cstring>
using namespace std;

const int MAX = 1000+1;

int map[MAX];
bool visited[MAX];
int n;

void check(int idx){
	while(!visited[idx]){
		visited[idx] = 1;
		idx = map[idx];
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t; cin >> t;
	
	while(t--){
		memset(map,0,sizeof(map));
		memset(visited,0,sizeof(visited));
		
		cin >> n;
		
		for(int i=1;i<=n;i++){
			int tmp; cin >> tmp;
			
			map[i] = tmp;
		}
		
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(!visited[i]){
				cnt++;
				check(i);
			}
		}
		cout << cnt << "\n";
	}
}
