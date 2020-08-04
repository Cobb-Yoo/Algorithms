#include <iostream>
#include <cstring>
#include <deque>
#include <queue>
using namespace std;

queue<pair<int,char>> command;
deque<pair<int,int>> snake;

int n,k;
int map[100][100]; // 0 : empty, 1 : snake, 2 : apple
int answer = 0;
int option[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
int navi = 0;

bool moveCheck(){
	answer++;
	
	int next_y = snake.front().first + option[navi][0];
	int next_x = snake.front().second + option[navi][1];
	
	if(next_y < 0 || next_y >= n || next_x < 0 || next_x >= n) return 0;
	if(map[next_y][next_x] == 1) return 0;
	
	if(map[next_y][next_x] == 0){
		map[snake.back().first][snake.back().second] = 0;
		snake.pop_back();
	}	
	map[next_y][next_x] = 1;
	snake.push_front({next_y,next_x});
	
	if(answer == command.front().first){
		if(command.front().second == 'D') navi = (navi+1)%4;
		else navi = (navi-1+4)%4;
		
		command.pop();
	}
	
	return 1;
}	

int main(){
	memset(map,0,sizeof(map));
	
	cin >> n >> k;
	
	for(int i=0;i<k;i++){
		int a, b;
		cin >> a >> b;
		map[a-1][b-1] = 2;
	}
	
	int l; cin >> l;
	
	for(int i=0;i<l;i++){
		int a; char b;
		cin >> a >> b;
		
		command.push({a,b});
	}
	
	snake.push_back({0,0});
	map[0][0] = 1;
	
	while(1){
		if(!moveCheck())
			break;
	}
	
	cout << answer << endl << endl;
}
