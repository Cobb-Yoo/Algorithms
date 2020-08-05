#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 8;
int option[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
int n,m;
int answer = 987654321;
int map[MAX][MAX];
int copyMap[MAX][MAX];
vector<pair<int,int>> cctv;
vector<int> angle;
bool visited[MAX][MAX][4];

void copy(){
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			copyMap[i][j] = map[i][j];
		}
	}
}

int check(){
	int result = 0;
	
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(copyMap[i][j] == 0) result++;
		}
	}
	
	return result;
}

void bfs(int cnt){
	if(cnt == cctv.size()){
		for(int i=0;i<angle.size();i++){
			int y = cctv[i].first;
			int x = cctv[i].second;
			
			for(int j=0;j<4;j++){
				if(visited[y][x][j]){
					int nextY = y + option[(angle[i]+j)%4][0];
					int nextX = x + option[(angle[i]+j)%4][1];
					
					while(1){
						if(0>nextY||nextY>=n || 0>nextX||nextX>=m) break;
						if(copyMap[nextY][nextX] == 6) break;
						
						if(copyMap[nextY][nextX] == 0) copyMap[nextY][nextX] = -1;
						
						nextY += option[(angle[i]+j)%4][0];
						nextX += option[(angle[i]+j)%4][1];
					}
				}
			}
		}
		answer = min(answer, check());
		copy();
		return;
	}
	
	for(int i=0;i<4;i++){
		angle.push_back(i);
		bfs(cnt+1);
		angle.pop_back();
	}
}

int main(){
	cin >> n >> m;
	
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin >> map[i][j];
			
			if(0<map[i][j] && map[i][j]<6) {
				cctv.push_back({i,j});
				
				if(map[i][j] == 1){
					visited[i][j][0] = 1;
				}else if(map[i][j] == 2){
					visited[i][j][0] = 1;
					visited[i][j][2] = 1;
				}else if(map[i][j] == 3){
					visited[i][j][0] = 1;
					visited[i][j][1] = 1;
				}else if(map[i][j] == 4){
					visited[i][j][0] = 1;
					visited[i][j][1] = 1;
					visited[i][j][2] = 1;
				}else if(map[i][j] == 5){
					visited[i][j][0] = 1;
					visited[i][j][1] = 1;
					visited[i][j][2] = 1;
					visited[i][j][3] = 1;
				}
			}
		}
	}
	
	copy();
	bfs(0);
	
	cout << answer << endl;
}
