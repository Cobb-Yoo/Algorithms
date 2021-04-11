#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 501;

int n,m;
bool visited[MAX][MAX];
bool map[MAX][MAX];
int option[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
vector<int> answer;

bool cmp(int a, int b){
	return a > b;
}

void solve(int a, int b){
	if(visited[a][b]) return;
	visited[a][b] = 1;
	
	int check = 1;
	
	queue<pair<int,int>> q;
	q.push({a,b});
	
	while(!q.empty()){
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		
		for(int i=0;i<4;i++){
			int nextY = y + option[i][0];
			int nextX = x + option[i][1];
			
			if(0<=nextY&&nextY<n && 0<=nextX&&nextX<m){
				if(!visited[nextY][nextX] && map[nextY][nextX]){
					check++;
					visited[nextY][nextX] = 1;
					q.push({nextY,nextX});
				}
			}
		}
	}
	
	answer.push_back(check);
}

int main(){
	cin >> n >> m;
	
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin >> map[i][j];
		}
	}
	
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(map[i][j]) solve(i,j);
		}
	}
	
	sort(answer.begin(), answer.end(), cmp);
	
	if(answer.size() == 0){
		cout << 0 << endl << 0;
	}else{
		cout << answer.size() << endl;
		cout << answer[0] << endl;
	}
}
