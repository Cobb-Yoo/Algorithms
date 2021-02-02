#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
#include <string>
using namespace std;

string map[12];
bool visited[12][6];
int option[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
int cnt;

bool cmp(pair<int,int> a, pair<int,int> b){
	if(a.second < b.second) return 1;
	else if(a.second == b.second) return a.first < b.first;
	else return 0;
}


int solve(){
	queue<pair<int,int>> q;
	
	while(1){
		vector<pair<int,int>> v;
		memset(visited,0,sizeof(visited));
		
		for(int i=11;i>=0;i--){
			for(int j=0;j<6;j++){
				if(map[i][j] == '.') continue;
				
				queue<pair<int,int>> popped;
				char c = map[i][j];
				q.push({i,j});
				visited[i][j] = 1;
				
				while(!q.empty()){
					int y = q.front().first;
					int x = q.front().second;
					q.pop();
					
					popped.push({y, x});
					
					for(int i=0;i<4;i++){
						int nextY = y + option[i][0];
						int nextX = x + option[i][1];
						
						if(0<=nextY&&nextY<12 && 0<=nextX&&nextX<6){
							if(!visited[nextY][nextX] && c == map[nextY][nextX]){
								visited[nextY][nextX] = 1;
								q.push({nextY,nextX});
							}
						}
					}
				}
				
				
				
				if(popped.size() >= 4){
					while(!popped.empty()){
						v.push_back({popped.front().first, popped.front().second});
						popped.pop();
					}
				}
			}
		}
		
		if(v.size() > 0){
			sort(v.begin(), v.end(), cmp);
			for(int i=0;i<v.size();i++){
				for(int j=v[i].first;j>0;j--) map[j][v[i].second] = map[j-1][v[i].second];
				map[0][v[i].second] = '.';
			}
			cnt++;
		}
		else break;
	}
	return cnt;
}

int main(){
	for(int i=0;i<12;i++) cin >> map[i];
	
	cout << solve();
}
