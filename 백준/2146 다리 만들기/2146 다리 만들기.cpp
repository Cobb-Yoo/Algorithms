#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int map[100][100];
int n;
int option[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
queue<pair<int,int>> edge;
int answer = 987654321;
int arr[100][100];

void getlen(int a,int b){
	queue<pair<int,int>> q;
	q.push({a,b});
	arr[a][b] = 0;
	
	while(!q.empty()){
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		
		for(int i=0;i<4;i++){
			int nextY = y + option[i][0];
			int nextX = x + option[i][1];
			
			if(0<=nextY&&nextY<n && 0<=nextX&&nextX<n){
				if(arr[nextY][nextX] == -1 && map[nextY][nextX] == 0){
					arr[nextY][nextX] = arr[y][x] + 1;
					q.push({nextY, nextX});
				}
				else if(arr[nextY][nextX] == -1 && map[nextY][nextX] != map[a][b]){
					answer = min(answer, arr[y][x]);
					return;
				}
			}
		}
	}
}

void f(int a, int b, int idx){
	queue<pair<int,int>> q;
	q.push({a,b});
	map[a][b] = idx;
	
	while(!q.empty()){
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		
		for(int i=0;i<4;i++){
			int nextY = y + option[i][0];
			int nextX = x + option[i][1];
			
			if(0<=nextY&&nextY<n && 0<=nextX&&nextX<n){
				if(map[nextY][nextX] == 1){
					map[nextY][nextX] = idx;
					q.push({nextY, nextX});
				}
			}
		}
		
		bool flag = 0;
		for(int i=0;i<4;i++){
			int nextY = y + option[i][0];
			int nextX = x + option[i][1];
			
			if(0<=nextY&&nextY<n && 0<=nextX&&nextX<n && map[nextY][nextX]==0){
				flag = 1;
				break;
			}
		}
		if(flag) edge.push({y,x});
	}
}

int main(){
	memset(map,0,sizeof(map));
	
	cin >> n;
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin >> map[i][j];
		}
	}
	
	int idx=2;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(map[i][j] == 1) f(i,j, idx++);
		}
	}
	
	while(!edge.empty()){
		memset(arr,-1,sizeof(arr));
		getlen(edge.front().first, edge.front().second);
		edge.pop();
	}
	
	cout << answer << endl;
}
