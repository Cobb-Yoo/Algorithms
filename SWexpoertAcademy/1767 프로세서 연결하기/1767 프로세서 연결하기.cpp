#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n;
bool map[12][12];
vector<pair<int,int>> v;
int option[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
int cnt;

int check(int idx, int op){
	int result = 0;
	
	int y = v[idx].first + option[op][0];
	int x = v[idx].second + option[op][1];
	
	while(0<=y&&y<n && 0<=x&&x<n){
		if(map[y][x] != 0) {
			return 13;
		}
		
		map[y][x] = 1;
		y += option[op][0];
		x += option[op][1];
		result++;
	}
	
	return result;
}

void solve(int idx, int sum){
	if(idx == v.size()){
		cnt = min(cnt, sum);
		return;
	}
	
	int copy[n][n];
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			copy[i][j] = map[i][j];
		}
	}
	
	for(int i=0;i<4;i++){
		int tmp = check(idx, i);
		sum += tmp;
		
		solve(idx+1, sum);
		
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				map[i][j] = copy[i][j];
			}
		}	
		sum -= tmp;
	}
}

int main(){
	
	int T; cin >> T;
	
	for(int t=1;t<=T;t++){
		v.clear();
		cnt = 978654321;
		
		cin >> n;
		int initCnt=0;
		
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				cin >> map[i][j];
				
				if(map[i][j] == 1){
					if(i == 0 || i == n-1 || j == 0 || j == n-1) initCnt++;
					else v.push_back({i,j});
				}
			}
		}
		
		solve(0, 0);
		
		cout << "#" << t << " " << cnt << "\n";
	}
}
