#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int n;
int map[100][100];
bool visited[100][100];
int m = 0;
int answer = 0;
int option[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};

void bfs(int height){
	int cnt = 0;
	memset(visited,0,sizeof(visited));
	
	queue<pair<int,int>> q;
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(!visited[i][j] && map[i][j] > height){
				q.push({i,j});
				visited[i][j] = 1;
				
				while(!q.empty()){
					int y = q.front().first;
					int x = q.front().second;
					q.pop();
					
					for(int i=0;i<4;i++){
						int next_y = y + option[i][0];
						int next_x = x + option[i][1];
						
						if(0<=next_y&&next_y<n && 0<=next_x&&next_x<n){
							if(!visited[next_y][next_x] && map[next_y][next_x] > height){
								visited[next_y][next_x] = 1;
								q.push({next_y, next_x});
							}
						}
					}
				}
				
				cnt++;
			}
		}
	}	
	
	answer = max(cnt, answer);
}

int main(){
	int m=0;
	cin >> n;
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin >> map[i][j];
			
			m = max(map[i][j], m);
		}
	}
	
	for(int i=0;i<=m;i++) bfs(i);
	
	cout << answer << endl;
}
