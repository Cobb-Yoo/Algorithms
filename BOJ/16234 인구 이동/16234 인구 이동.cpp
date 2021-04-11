#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int n,l,r;
int map[50][50];
bool visited[50][50];
int option[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
int people, cnt;
vector<pair<int,int>> v;

void dfs(int a, int b){
	for(int i=0;i<4;i++){
		int y = a+option[i][0];
		int x = b+option[i][1];
		
		int dif = abs(map[a][b] - map[y][x]);
		if(0<=y&&y<n && 0<=x&&x<n){
			if(l<=dif && dif<=r && !visited[y][x]){
				visited[y][x] = 1;
				v.push_back({y,x});
				cnt++;
				people+=map[y][x];
				dfs(y,x);
			}
		}
	}
}

int main(){
	int answer = 0;
	
	cin >> n >> l >> r;
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin >> map[i][j];
		}
	}
	int result = 0;
	while(1){
		memset(visited,0,sizeof(visited));
		
		bool flag = 0;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(visited[i][j]) continue;
				visited[i][j] = 1;
			
				people = map[i][j];
				cnt = 1;
			
				v.clear();
				v.push_back({i,j});
				dfs(i,j);
			
				if(cnt >= 2){
					flag = 1;
					for(int k=0;k<v.size();k++){
						map[v[k].first][v[k].second] = people/cnt;
					}
				}
			}
		}
		
		if(flag) answer++;
		else break;
	}
	
	cout << answer << endl;
}
