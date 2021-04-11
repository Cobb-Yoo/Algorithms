#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int MAX = 8;

int n,m;
vector<vector<int>> v;
vector<vector<int>> tmp;
int answer;
int option[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};

void init(){
	cin >> n >> m;
	for(int i=0;i<n;i++){
		vector<int> tmp;
		
		for(int j=0;j<m;j++){
			int n; cin >> n;
			tmp.push_back(n);
		}
		
		v.push_back(tmp);
	}
	answer = 0;
}

void bfs(){
	vector<vector<int>> virus = tmp;
	
	queue<pair<int,int>> q;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(virus[i][j] == 2) q.push({i,j});
		}
	}
	
	while(!q.empty()){
		int a = q.front().first;
		int b = q.front().second;
		q.pop();
		
		for(int i=0;i<4;i++){
			int x = a + option[i][0];
			int y = b + option[i][1];
			
			if(0<=x&&x<n&&0<=y&&y<m && virus[x][y]==0){
				virus[x][y] = 2;
				q.push({x,y});
			}
		}
	}
	
	int cnt = 0;
	
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(virus[i][j] == 0) cnt++;
		}
	}
	
	answer = max(cnt,answer);
}

void wall(int cnt){
	if(cnt == 3){
		bfs();
		return;
	}
	
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(tmp[i][j] == 0){
				tmp[i][j] = 1;
				wall(cnt+1);
				tmp[i][j] = 0;
			}
		}
	}
}

int main(){
	init();
	
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(v[i][j] == 0){
				tmp = v;
				
				tmp[i][j] = 1;
				wall(1);
				tmp[i][j] = 0;
			}
		}
	}
	
	cout << answer << endl;
}
