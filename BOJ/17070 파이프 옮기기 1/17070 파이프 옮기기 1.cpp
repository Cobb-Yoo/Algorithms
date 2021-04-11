#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<int> v;
queue<pair<int, pair<int,int>>> q;
int option[3][2] = {{0,1},{1,1},{1,0}};
int n;
bool map[16][16];
int cnt = 0;

void solve(){
	q.push({0,{0,1}});
	
	while(!q.empty()){
		int curStatus = q.front().first;
		int y = q.front().second.first;
		int x = q.front().second.second;
		q.pop();
		
		if(y == n-1 && x == n-1) {
			cnt++;
			continue;
		}
		
		for(int i=0;i<3;i++){
			if((i==0 && curStatus==2) || (i==2 && curStatus==0)) continue;
			
			int nextY = y + option[i][0];
			int nextX = x + option[i][1];
			
			if(0<=nextY&&nextY<n && 0<=nextX&&nextX<n && !map[nextY][nextX]){
				if(i==1 && (map[y+1][x]==1 || map[y][x+1]==1)) continue;
				
				q.push({i,{nextY,nextX}});
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin >> map[i][j];
		}
	}
	
	solve();
	
	cout << cnt << endl;
}
