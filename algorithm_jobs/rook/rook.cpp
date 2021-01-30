#include <iostream>
#include <queue>
using namespace std;

int map[8][8];
queue<pair<int,int>> q;
int option[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

int main(){
	for(int i=0;i<8;i++){
		for(int j=0;j<8;j++){
			cin >> map[i][j];
			
			if(map[i][j] == 2) q.push({i,j});
		}
	}
	
	int answer = 0;
	while(!q.empty()){
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		
		for(int i=0;i<4;i++){
			int nextY = y;
			int nextX = x;
			
			while(1){
				nextY += option[i][0];
				nextX += option[i][1];
				
				if(0>nextY || nextY >= 8 || 0>nextX || nextX >= 8) break;
				if(map[nextY][nextX] == 1) {
					answer++;
					break;	
				}
				else if(map[nextY][nextX]) break;
			}
		}
	}
	
	if(answer) cout << 1;
	else cout << 0;
}
