#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

bool visited[100][100];
int n,m,k;
int option[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
vector<int> area;

void countArea(int a, int b){
	queue<pair<int,int>> q;
	q.push({a,b});
	visited[a][b] = 1;
	int result = 1;
	
	while(!q.empty()){
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		
		for(int i=0;i<4;i++){
			int nextY = y + option[i][0];
			int nextX = x + option[i][1];
			
			if(0<=nextY&&nextY<m && 0<=nextX&&nextX<n){
				if(!visited[nextY][nextX]){
					visited[nextY][nextX] = 1;
					q.push({nextY, nextX});
					result++;
				}
			}
		}
	}
	
	area.push_back(result);
}

int main(){
	memset(visited,0,sizeof(visited));
	
	cin >> m >> n >> k;
	
	for(int T=0;T<k;T++){
		int sy, sx;
		int ey, ex;
		
		cin >> sx >> sy;
		cin >> ex >> ey;
		
		for(int i=sy;i<ey;i++){
			for(int j=sx;j<ex;j++) {
				visited[i][j] = 1;
			}
		}
	}
	

	
	int answer = 0;
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			if(!visited[i][j]) {
				countArea(i,j);
				answer++;
			}
		}
	}
	
	sort(area.begin(), area.end());
	
	cout << answer << endl;
	for(int i=0;i<area.size();i++) cout << area[i] << " ";
}
