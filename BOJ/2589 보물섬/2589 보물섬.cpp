#include <iostream>
#include <cstring>
#include <string>
#include <queue>
using namespace std;

char map[50][50];
int dis[50][50];
int n,m;
int answer = 0;
int option[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};

void findOnepiece(int a, int b){
	memset(dis,-1,sizeof(dis));
	queue<pair<int,int>> q;
	q.push({a,b});
	dis[a][b] = 0;
	
	while(!q.empty()){
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		
		for(int i=0;i<4;i++){
			int next_y = y+option[i][0];
			int next_x = x+option[i][1];
			
			if(0<=next_y&&next_y<n && 0<=next_x&&next_x<m){
				if(dis[next_y][next_x]==-1 && map[next_y][next_x] == 'L'){
					dis[next_y][next_x] = dis[y][x]+1;
					answer = max(answer, dis[next_y][next_x]);
					q.push({next_y,next_x});
				}
			}
		}
	}
}

int main(){	
	cin >> n >> m;
	queue<pair<int,int>> landq;
	
	for(int i=0;i<n;i++){
		cin >> map[i];
		for(int j=0;j<m;j++){
			if(map[i][j] == 'L') landq.push({i,j});
		}
	}
	
	while(!landq.empty()){
		findOnepiece(landq.front().first ,landq.front().second);
		landq.pop();
	}
	
	
	cout << answer << endl;
}
