#include <iostream>
#include <queue>
using namespace std;

int map[101][101];
int option[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
int n;
int a,b,r;

void solve(){
	queue<pair<int,int>> q;
	q.push({a,b});
	
	while(!q.empty()){
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		
		for(int i=0;i<4;i++){
			int nextY = y+option[i][0];
			int nextX = x+option[i][1];
			
			if(0<nextY&&nextY<=n && 0<nextX&&nextX<=n){
				if(!map[nextY][nextX]){
					map[nextY][nextX] = map[y][x]+1;
					if(map[y][x] < r-1) q.push({nextY,nextX});
				}
			}
		}
	}
}

int main(){
	cin >> n;
	cin >> a >> b >> r;
	
	solve();
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==a && j==b) cout << "x ";
			else cout << map[i][j] << " ";
		}
		cout << endl;
	}
}
