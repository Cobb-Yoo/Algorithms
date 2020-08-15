#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int option[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
int r,c,t;
int map[50][50];
queue<pair<int,int>> machine;
int tmpMap[50][50];
int answer = 0;
int cnt=0;

void copyMap(){
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			map[i][j] = tmpMap[i][j];
		}
	}
	memset(tmpMap,0,sizeof(tmpMap));
}

void init(){
	cin >> r >> c >> t;
	
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			cin >> map[i][j];
			
			if(map[i][j] == -1) machine.push({i,j});
		}
	}
}

void dustCounting(){
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			if(map[i][j] == -1) continue;
			answer += map[i][j];
		}
	}
}

void dusting() {
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			if(map[i][j] == 1) tmpMap[i][j] += 1;
			else if(map[i][j] == -1) tmpMap[i][j] = -1;
			else if(map[i][j] > 1){
				int num=0;
				for(int k=0;k<4;k++){
					int y = i + option[k][0];
					int x = j + option[k][1];
					
					if(0<=y&&y<r && 0<=x&&x<c && map[y][x] != -1){
						tmpMap[y][x] += map[i][j]/5;
						num += map[i][j]/5;
					}
				}
				tmpMap[i][j] += map[i][j] - num;
			}
		}
	}
	
	copyMap();
}

void clearing(){
	int y = machine.front().first;
	int x = machine.front().second;
	
	for(int i=y-1;i>=0;i--) {
		if(i==0) map[0][0] = map[0][1]; 
		else map[i][0] = map[i-1][0];
	}
	for(int i=0;i<c;i++){
		if(i==c-1) map[0][i] = map[1][i];
		else map[0][i] = map[0][i+1];
	}
	for(int i=0;i<=y;i++){
		if(i==y) map[i][c-1] = map[i][c-2];
		else map[i][c-1] = map[i+1][c-1];
	}
	for(int i=c-1;i>=1;i--){
		if(i==1) map[y][i] = 0;
		else map[y][i] = map[y][i-1];
	}
	
	
	for(int i=y+2;i<r;i++){
		if(i==r-1) map[i][0] = map[i][1];
		else map[i][0] = map[i+1][0];
	}
	for(int i=0;i<c;i++){
		if(i==c-1) map[r-1][i] = map[r-2][i];
		else map[r-1][i] = map[r-1][i+1];
	}
	for(int i=r-1;i>=y+1;i--){
		if(i==y+1) map[i][c-1] = map[i][c-2];
		else map[i][c-1] = map[i-1][c-1];
	}
	for(int i=c-1;i>=1;i--){
		if(i==1) map[y+1][i] = 0;
		else map[y+1][i] = map[y+1][i-1];
	}
}

int main(){
	memset(map,0,sizeof(map));
	// 1. 미세먼지의 확산
	// 2. 공기청정기의 바람의 확산 (위, 아래) 
	
	init();
	
	while(t--){
		dusting();
		clearing();
	}
	
	dustCounting();
	
	cout << answer << endl;
}
