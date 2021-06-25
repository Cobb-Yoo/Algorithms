#include <bits/stdc++.h>
using namespace std;

const int Max = 19;
int graph[Max][Max];
bool visited[4][Max][Max];
int option[4][2] = {{0,1},{1,1},{1,0},{-1,1}};

int solve(int y, int x, int op){
	int cnt = 1;
	
	visited[op][y][x] = 1;
	
	int ny = y + option[op][0];
	int nx = x + option[op][1];
	
	if(0<=ny&&ny<Max && 0<=nx&&nx<Max && graph[y][x] == graph[ny][nx]){
		cnt += solve(ny,nx,op);
	}
	
	return cnt;
}

int main(){
	for(int i=0;i<Max;i++){
		for(int j=0;j<Max;j++){
			cin >> graph[i][j];
		}
	}
	
	for(int i=0;i<Max;i++){
		for(int j=0;j<Max;j++){
			if(!graph[j][i]) continue;
			
			for(int k=0;k<4;k++){
				if(!visited[k][j][i]){
				
					if(solve(j,i,k) == 5){
						cout << graph[j][i] << endl;
						cout << j+1 << " " << i+1<< endl;
						exit(0);
					}
				}
			}	
		}
	}
	
	cout << 0;
}
