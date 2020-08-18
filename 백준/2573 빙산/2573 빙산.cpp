#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
using namespace std;

const int MAX = 300;

int option[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
int n,m;
bool visited[MAX][MAX];
int map[MAX][MAX];
int copyMap[MAX][MAX];

void melting(){
	memset(copyMap,0,sizeof(copyMap));
	
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(map[i][j] == 0) continue;
			
			int cnt = 0;
			for(int k=0;k<4;k++){
				int y = i + option[k][0];
				int x = j + option[k][1];
				
				if(0<=y&&y<n && 0<=x&&x<m){
					if(map[y][x] == 0) cnt++;
				}
			}
			
			copyMap[i][j] = max(map[i][j]-cnt, 0);
		}
	}
	
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			map[i][j] = copyMap[i][j];
		}
	}
}

void dfs(int y, int x){
	visited[y][x] = 1;
	
	for(int i=0;i<4;i++){
		int nextY = y + option[i][0];
		int nextX = x + option[i][1];
		
		if(0<=nextY&&nextY<n && 0<=nextX&&nextX<m){
			if(map[nextY][nextX] && !visited[nextY][nextX]){
				dfs(nextY,nextX);
			}
		}
	}
}

bool countArea(){

}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin >> map[i][j];
		}
	}
	
	int answer = 0;
	while(1){
		memset(visited,0,sizeof(visited));
	
		int result=0;
		bool flag = 0;
		
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(map[i][j] && !visited[i][j]){
					result++;
					if(result == 2){
						flag = 1;
						break;
					} 
				
					dfs(i,j);
				}
			}
		}
		
		if(flag) break;
		if(result == 0){
			answer = 0;
			break;
		}
		
		
		melting();
		answer++;
	}
	
	cout << answer << "\n";
}
