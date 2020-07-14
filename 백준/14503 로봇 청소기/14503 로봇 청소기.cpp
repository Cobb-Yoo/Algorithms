#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int option[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
int visited[50][50];
int answer = 0;
int n,m;

void bfs(int a,int b,int c){
	queue<pair<pair<int,int>, int>> q;
	q.push({{a,b},c});
	
	while(!q.empty()){
		int x = q.front().first.first;
		int y = q.front().first.second;
		int dir = q.front().second;
		
		if(!visited[x][y]){
			visited[x][y] = 2;
			answer++;
		}
		
		q.pop();
		
		bool flag = 0;
		for(int i=0;i<4;i++){
			int nextDir = (dir+(3-i))%4;
			int nextX = x + option[nextDir][0];
			int nextY = y + option[nextDir][1];
			
			if(0<=nextX&&nextX<n && 0<=nextY&&nextY<m && visited[nextX][nextY] == 0){
				q.push({{nextX,nextY},nextDir});
				flag = 1;
				break;
			}
		}
		
		if(!flag){
			int beforeX = x - option[dir][0];
			int beforeY = y - option[dir][1];
			
			if (0<=beforeX && beforeX<n && 0<=beforeY && beforeY<m && visited[beforeX][beforeY] != 1)
				q.push({{beforeX, beforeY},dir});
			else break;
		}
	}
}

int main(){
	cin >> n >> m;
	int a,b,c;
	cin >> a >> b >> c;
	
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin >> visited[i][j];
		}
	}
	
	bfs(a,b,c);
	
	cout << answer << endl;
}
