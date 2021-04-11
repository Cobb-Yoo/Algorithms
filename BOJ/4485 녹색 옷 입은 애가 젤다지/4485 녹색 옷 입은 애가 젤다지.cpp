#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int map[125][125];
int visited[125][125];
int n;
int problemCnt = 0;
int answer;
int option[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};

void f(){
	queue<pair<int,int>> q;
	q.push({0,0});
	visited[0][0] = map[0][0];
	
	while(!q.empty()){
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		
		for(int i=0;i<4;i++){
			int ny = y + option[i][0];
			int nx = x + option[i][1];
			
			if(0<=ny&&ny<n && 0<=nx&&nx<n){
				if(visited[ny][nx] > visited[y][x]+map[ny][nx]){
					visited[ny][nx] = visited[y][x]+map[ny][nx];
					q.push({ny,nx});
				}
			}
		}
	}
	
	answer = visited[n-1][n-1];
}
#include <iostream>
using namespace std;

int main(){
	
}
int main(){
	while(cin >> n && n != 0){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				visited[i][j] = 987654321;
			}
		}
		
		problemCnt++;
		answer = 0;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				cin >> map[i][j];
			}
		}
		
		f();
		
		cout << "Problem " << problemCnt<<": " << answer << endl;
	}
}
