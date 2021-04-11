#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

const int MAX = 100+1;
int n,m;
bool map[MAX][MAX];
bool visited[MAX][MAX];
bool tmp_map[MAX][MAX];
int cnt;
int option[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
int answer, time;

void Swap(){
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			map[i][j] = tmp_map[i][j];
		}
	}
}

void solve(){
	while(cnt != 0){
		queue<pair<int,int>> q;
		q.push({0,0});
		
		answer = cnt;
		time++;
		
		memset(visited,0,sizeof(visited));
		
		while(!q.empty()){
			int y = q.front().first;
			int x = q.front().second;
			q.pop();
		
			for(int i=0;i<4;i++){
				int nextY = y + option[i][0];
				int nextX = x + option[i][1];
				
				if(0<=nextY&&nextY<n && 0<=nextX&&nextX<m && !visited[nextY][nextX]){
					if(!map[nextY][nextX]){
						visited[nextY][nextX] = 1;
						q.push({nextY,nextX});
					}
					else{
						visited[nextY][nextX] = 1;
						tmp_map[nextY][nextX] = 0;
						cnt--;
					}
				}
			}
		}
		Swap();
	}
}

int main(){
	cin >> n >> m;
	
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin >> map[i][j];
			tmp_map[i][j] = map[i][j];
			
			if(map[i][j]) cnt++;
		}
	}
	
	solve();
	
	cout << time << endl << answer << endl;
}
