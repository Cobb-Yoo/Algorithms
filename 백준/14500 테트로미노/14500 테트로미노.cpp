#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 500;
int option[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
int n,m;
int map[MAX][MAX];
bool visited[MAX][MAX];

int dfs(int y, int x, int cnt){
	if(cnt == 4) return map[y][x];
	
	int sum = 0;
	for(int i=0;i<4;i++){
		int nextY = y + option[i][0];
		int nextX = x + option[i][1];
		
		if (0<=nextY&&nextY<n && 0<=nextX&&nextX<m && !visited[nextY][nextX]){
			visited[nextY][nextX] = 1;
			sum = max(sum, map[y][x] + dfs(nextY,nextX,cnt+1));
			visited[nextY][nextX] = 0;
		}
	}
	
	return sum;
}

int middle(int y, int x){
	int result = 0;


    if (y >= 1 && x >= 1 && x < m - 1) result = max(result, map[y][x - 1] + map[y][x] + map[y - 1][x] + map[y][x + 1]);
	if (y >= 1 && y < n - 1 && x < m - 1) result = max(result, map[y - 1][x] + map[y][x] + map[y][x + 1] + map[y + 1][x]);
	if (y >= 0 && y < n - 1 && x < m - 1) result = max(result, map[y][x - 1] + map[y][x] + map[y + 1][x] + map[y][x + 1]);
	if (y >= 1 && y < n - 1 && x >= 1) result = max(result, map[y - 1][x] + map[y][x] + map[y][x - 1] + map[y + 1][x]);

	return result;
}

int main(){
	cin >> n >> m;
	
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin >> map[i][j];
		}
	}
	
	int answer = 0;
	
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			visited[i][j] = 1;
			answer = max({answer, dfs(i,j,1), middle(i,j)});
			visited[i][j] = 0;
		}
	}
	
	cout << answer << endl;
}
