#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

const int Max = 50;
int map[Max+1][Max+1];
int vTime[Max+1][Max+1];
int option[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
int n,m,answer;
vector<pair<int,int>> v;
vector<bool> bv;

void check(){
	int tmp = 0;
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(map[i][j] == 1) continue;
			
			if(vTime[i][j] == -1) return;
			
			tmp = max(tmp, vTime[i][j]);
		}
	}
	
	//cout << "TEST_STRAT++++++++++++++++++++++\n";
	//for(int i=0;i<n;i++){
	//	for(int j=0;j<n;j++){
	//		cout << vTime[i][j] << " ";
	//	}
	//	cout << endl;
	//}
	//cout << "TEST_END++++++++++++++++++++++\n\n";
	
	answer = min(answer, tmp);
}

void solve(){
	//cout << "solve\n";
	memset(vTime,-1,sizeof(vTime));
	queue<pair<int,int>> q;
	
	int len = bv.size();
	for(int i=0;i<len;i++){
		if(bv[i]) {
			q.push(v[i]);
			vTime[v[i].first][v[i].second] = 0;
		}
	}
	
	while(!q.empty()){
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		
		for(int i=0;i<4;i++){
			int nextY = y + option[i][0];
			int nextX = x + option[i][1];
			
			if(0<=nextY&&nextY<n && 0<=nextX&&nextX<n){
				if(vTime[nextY][nextX] == -1 && map[nextY][nextX] != 1){
					vTime[nextY][nextX] = vTime[y][x]+1;
					q.push({nextY, nextX});
				}
			}
		}
	}
}

int main(){
	answer = 987654321;
	cin >> n >> m;
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin >> map[i][j];
			
			if(map[i][j] == 2) {
				v.push_back({i,j});
				map[i][j] = 0;
			}
		}
	}
	
	sort(v.begin(), v.end());
	int len = v.size();
	for(int i=0;i<len;i++){
		if(i < m) bv.push_back(1);
		else bv.push_back(0);
	}
	
	do{
		solve();
		check();
	}while(prev_permutation(bv.begin(), bv.end()));
	
	if(answer == 987654321) cout << -1;
	else cout << answer << endl;
}
