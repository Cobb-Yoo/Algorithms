#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int n, m;
int arr[101][101];
bool check[101][101];
int env[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

void bfs(int x,int y){
	int cur_y = 0;
	int cur_x = 0;
	
	queue<pair<int, int>> q;
	q.push(pair<int,int>(cur_y,cur_x));
	arr[cur_y][cur_x] =1;
	
	while(!q.empty()){
		cur_y = q.front().first;
		cur_x = q.front().second;
		q.pop();
		
		for(int i=0;i<4;i++){
			int ny = cur_y + env[i][0];
			int nx = cur_x + env[i][1];
		
			if(0 <= ny && ny <= n && 0 <= nx && nx <= m && check[ny][nx] && arr[ny][nx]==0){
				arr[ny][nx] = arr[cur_y][cur_x] + 1;
				q.push(pair<int, int>(ny, nx));
			}
		}
	}
}

int main(){
	cin >> n >> m;
	
	string tmp;
	for(int i=0;i<n;i++){
		cin >> tmp;
		for(int j=0;j<m;j++){
			check[i][j] = tmp[j] - '0';
		}
	}
	
	bfs(0,0);
	
	cout << arr[n-1][m-1] << endl;
	
}
