#include <bits/stdc++.h>
using namespace std;

const int Max = 200;
const int inf = 987654321;
int horseMoving[8][2] = {{1,-2},{2,-1},{2,1},{1,2},{-1,2},{-2,1},{-2,-1},{-1,-2}};
int option[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
int k,w,h;
bool visited[Max+1][Max+1][30+1];
int Map[Max+1][Max+1];

void solve(){
	queue<pair<pair<int,int>,pair<int,int>>> q;
	q.push({{0,0},{0,0}});
	visited[0][0][0]=1;
	
	while(!q.empty()){
		int y = q.front().first.first;
		int x = q.front().first.second;
		int cnt = q.front().second.first;
		int val = q.front().second.second;
		q.pop();
		
		if(y == h-1 && x == w-1){
			cout << cnt;
			return;
		}
		
		if(val < k){
			for(int i=0;i<8;i++){
				int nextY = y + horseMoving[i][0];
				int nextX = x + horseMoving[i][1];
				
				if(0<=nextY&&nextY<h && 0<=nextX&&nextX<w){
					if(Map[nextY][nextX] == 0 && !visited[nextY][nextX][val+1]){
						visited[nextY][nextX][val+1] = 1;
						q.push({{nextY,nextX},{cnt+1, val+1}});
					}
				}
			}
		}
		
		for(int i=0;i<4;i++){
			int nextY = y + option[i][0];
			int nextX = x + option[i][1];
				
			if(0<=nextY&&nextY<h && 0<=nextX&&nextX<w){
				if(Map[nextY][nextX] == 0 && !visited[nextY][nextX][val]){
					visited[nextY][nextX][val] = 1;
					q.push({{nextY,nextX},{cnt+1, val}});
				}
			}
		}
	}
	
	cout << -1;
}

int main(){
	cin >> k >> w >> h;
	
	for(int i=0;i<h;i++){
		for(int j=0;j<w;j++){
			cin >> Map[i][j];
		}
	}
	
	solve();
}
