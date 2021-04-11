#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int r,c,si,sj,ei,ej;
char map[50][50];
int water_map[50][50];
int move_map[50][50];
int option[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
bool flag = 0;
int answer = -1;
queue<pair<int,int>> q_water;

void water(){
	while(!q_water.empty()){
		int y = q_water.front().first;
		int x = q_water.front().second;
		q_water.pop();
		
		for(int i=0;i<4;i++){
			int next_y = y + option[i][0];
			int next_x = x + option[i][1];
			
			if(0<=next_y&&next_y<r && 0<=next_x&&next_x<c){
				if(water_map[y][x] == -1) water_map[y][x] = 0;
				
				if(water_map[next_y][next_x] == -1
				&& (map[next_y][next_x] == '.' || map[next_y][next_x] == 'S')){
					water_map[next_y][next_x] = water_map[y][x]+1;
					q_water.push({next_y,next_x});
				}
			}
		}
	}
}

void move(){
	queue<pair<int,int>> q_move;
	q_move.push({si,sj});
	move_map[si][sj] = 0;
	
	while(!q_move.empty()){
		int y = q_move.front().first;
		int x = q_move.front().second;
		q_move.pop();
		
		for(int i=0;i<4;i++){
			int next_y = y + option[i][0];
			int next_x = x + option[i][1];
			
			if(0<=next_y&&next_y<r && 0<=next_x&&next_x<c){
				
				if((map[next_y][next_x] == '.' || map[next_y][next_x] == 'D')
				&& (water_map[next_y][next_x] > move_map[y][x]+1 || water_map[next_y][next_x] == -1)
				&& move_map[next_y][next_x] == -1){
						
					move_map[next_y][next_x] = move_map[y][x]+1;
					if(next_y == ei && next_x == ej) {
						answer = move_map[next_y][next_x];
						flag = 1;
						return ;
					}
					q_move.push({next_y,next_x});
				}
			}
		}
	}
}

int main(){
	memset(water_map,-1,sizeof(water_map));
	memset(move_map,-1,sizeof(move_map));
	
	cin >> r >> c;
		
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			cin >> map[i][j];
			
			if(map[i][j] == 'D'){
				ei = i;
				ej = j;
			}else if(map[i][j] == 'S'){
				si = i;
				sj = j;
			}else if(map[i][j] == '*'){
				q_water.push({i,j});
			}
		}
	}
	
	water();
	move();
	
	if(flag) cout << answer << endl;
	else cout << "KAKTUS\n";
}
