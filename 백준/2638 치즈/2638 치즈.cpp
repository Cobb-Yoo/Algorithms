#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

const int MAX = 100+1;
bool map[MAX][MAX];
bool visited[MAX][MAX];
int chesses[MAX][MAX];
int n,m;
int total;
int option[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

void solve(){
	memset(visited,0,sizeof(visited));
	memset(chesses,0,sizeof(chesses));
	queue<pair<int,int>> q;
	q.push({0,0});
	visited[0][0] = 1;
	
	while(!q.empty()){
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		
		for(int i=0;i<4;i++){
			int nextY = y + option[i][0];
			int nextX = x + option[i][1];
			
			if(0<=nextY&&nextY<n && 0<=nextX&&nextX<m){
				if(!visited[nextY][nextX]){
					if(map[nextY][nextX]){
						chesses[nextY][nextX]++;
					}
					else{
						visited[nextY][nextX] = 1;
						q.push({nextY,nextX});
					}
				}
			}
		}
	}
	
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(chesses[i][j] >= 2){
				total--;
				map[i][j] = 0;
			}
		}
	}
}

int main(){
	cin >> n >> m;
	
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin >> map[i][j];
			
			if(map[i][j]) total++;
		}
	}
	
	int cnt=0;
	while(1){
		if(total){
			solve();
			cnt++;
		}
		else break;
	}
	
	cout << cnt << endl;
}
