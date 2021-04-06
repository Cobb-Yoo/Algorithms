#include <bits/stdc++.h>
using namespace std;

const int Max = 1501;
string arr[Max];
int option[4][2] = {{0,1},{1,0},{-1,0},{0,-1}};
queue<pair<int,int>> water;
vector<pair<int,int>> swan_index;
queue<pair<int,int>> swan;
bool visited[Max][Max];
int r,c;

void melt(){
	queue<pair<int,int>> q;
	
	while(!water.empty()){
		int y = water.front().first;
		int x = water.front().second;
		water.pop();
		
		for(int i=0;i<4;i++){
			int ny = y + option[i][0];
			int nx = x + option[i][1];
			
			if(0<=ny&&ny<r && 0<=nx&&nx<c){
				if(arr[ny][nx] == 'X'){
					arr[ny][nx] = '.';
					q.push({ny,nx});
				}
			}
		}
	}
	
	water = q;
}

bool check(){
	queue<pair<int,int>> q;
	
	while(!swan.empty()){
		int y = swan.front().first;
		int x = swan.front().second;
		visited[y][x] = 1;
		swan.pop();
		
		for(int i=0;i<4;i++){
			int ny = y + option[i][0];
			int nx = x + option[i][1];
			
			if(0<=ny&&ny<r && 0<=nx&&nx<c && !visited[ny][nx]){
				visited[ny][nx] = 1;
				
				if(arr[ny][nx] == '.') swan.push({ny,nx});
				else if(arr[ny][nx] == 'L') return 1;
				else if(arr[ny][nx] == 'X')	q.push({ny,nx});
			}
		}
	}
	
	swan = q;
	return 0;
}

int main(){
	cin >> r >> c;
	
	for(int i=0;i<r;i++){
		cin >> arr[i];
		
		for(int j=0;j<c;j++){
			if(arr[i][j] != 'X') water.push({i,j});
			if(arr[i][j] == 'L') swan_index.push_back({i,j});
		}
	}
	
	int day = 0;
	swan.push({swan_index[0].first, swan_index[0].second});
	visited[swan_index[0].first][swan_index[0].second];
	
	while(1){
		if(check()) break;
		melt();
		day++;
	}
	cout << day;
}
