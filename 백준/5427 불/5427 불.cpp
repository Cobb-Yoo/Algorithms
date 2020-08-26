#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
using namespace std;

int m,n;
char map[1000][1000];
bool visited[1000][1000];
int option[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};

pair<int,int> start;
vector<pair<int,int>> fire;

int bfs(){
	queue<pair<int,int>> q;
	queue<pair<int,int>> flame;
	
	q.push(start);
	for(int i=0;i<fire.size();i++) flame.push(fire[i]);
	int result = 0;
	
	while(!q.empty()){
		int flameLen = flame.size();
		for(int i=0;i<flameLen;i++){
			int y = flame.front().first;
			int x = flame.front().second;
			flame.pop();
			
			for(int j=0;j<4;j++){
				int nextY = y + option[j][0];
				int nextX = x + option[j][1];
				
				if(0<=nextY&&nextY<n && 0<=nextX&&nextX<m){
					if(map[nextY][nextX] == '.'){
						map[nextY][nextX] = '*';
						flame.push({nextY,nextX});
					}
				}
			}
		}
		
		int curLen = q.size();
		for(int i=0;i<curLen;i++){
			int y = q.front().first;
			int x = q.front().second;
			q.pop();
			
			if(0== y || y == n-1 || 0 == x || x == m-1) return result+1;
			
			for(int j=0;j<4;j++){
				int nextY = y + option[j][0];
				int nextX = x + option[j][1];
				
				if(0<=nextY&&nextY<n && 0<=nextX&&nextX<m){
					if(!visited[nextY][nextX] && map[nextY][nextX] != '*' && map[nextY][nextX] != '#'){
						visited[nextY][nextX] = 1;
						q.push({nextY,nextX});
					}
				}
			}
		}
		result++;
	}
	return -1;
}

int main(){
	int t; cin >> t;
	
	while(t--){
		memset(visited,0,sizeof(visited));
		cin >> m >> n;
		
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				cin >> map[i][j];
				
				if(map[i][j] == '@') start = {i,j};
				else if(map[i][j] == '*') fire.push_back({i,j});
			}
		}
		
		int answer = bfs();
		
		if(answer!=-1) cout << answer << endl;
		else cout << "IMPOSSIBLE\n";
	}
}
