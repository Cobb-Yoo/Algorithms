#include <iostream>
#include <queue>
#include <string>
#include <cstring>
using namespace std;

const int MAX = 1001;

int n,m;
bool graph[MAX][MAX];
int answer[MAX][MAX][2];
int option[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};

void init(){
	memset(answer,0,sizeof(answer));
}

int dfs(){
	queue<pair<pair<int,int>, int>> q;
	q.push({{0,0},1});
	answer[0][0][1] = 1;
	
	while(!q.empty()){
		int a = q.front().first.first;
		int b = q.front().first.second;
		int breakable = q.front().second;
		q.pop();
		
		if(a == n-1 && b == m-1) return answer[a][b][breakable];
		
		for(int i=0;i<4;i++){
			int x = a + option[i][0];
			int y = b + option[i][1];
			
			if(0 <= x && x < n && 0 <= y && y < m){
				if(graph[x][y] && breakable){
					answer[x][y][breakable-1] = answer[a][b][breakable]+1;
					q.push({{x,y}, breakable-1});
				}
				
				if(!graph[x][y] && !answer[x][y][breakable]){
					answer[x][y][breakable] = answer[a][b][breakable]+1;
					q.push({{x,y}, breakable});
				}
			}
		}
	}
	
	return -1;
}


int main(){
	cin >> n >> m;
	
	for(int i=0;i<n;i++){
		string tmp;
		cin >> tmp;
		
		for(int j=0;j<m;j++) graph[i][j] = tmp[j]-'0';
	}
	
	init();
	
	cout << dfs() << endl;
}
