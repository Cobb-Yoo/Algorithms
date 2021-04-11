#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

string graph[100];
int map[100][100];
int option[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
int n,m;

void bfs(){
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			map[i][j] = 987654321;
		}
	}
	
	queue<pair<int,int>> q;
	q.push({0,0});
	map[0][0] = 0;
	
	while(!q.empty()){
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		
		for(int i=0;i<4;i++){
			int nextY = y + option[i][0];
			int nextX = x + option[i][1];
			
			if(0<=nextY&&nextY<m && 0<=nextX&&nextX<n){
				if(graph[nextY][nextX] == '1') {
					if(map[nextY][nextX] > map[y][x] + 1){
						map[nextY][nextX] = map[y][x] + 1;
						q.push({nextY,nextX});
					}
				}
				else {
					if(map[nextY][nextX] > map[y][x]){
						map[nextY][nextX] = map[y][x];
						q.push({nextY,nextX});
					}
				}
			}
		}
	}
}

int main(){
	cin >> n >> m;
	
	for(int i=0;i<m;i++) cin >> graph[i];
	
	bfs();
	
	cout << map[m-1][n-1] << endl;
}
