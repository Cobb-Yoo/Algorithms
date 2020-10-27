#include <iostream>
using namespace std;

const int MAX = 30;

int n,m,h;
bool map[MAX][MAX];
bool flag;
int depth;

void solve(int y, int cnt){
	if(flag) return;
	
	if(depth == cnt){
		bool check = 1;
		for(int i=1;i<=n;i++){
			int row = i;
			for(int j=0;j<h;j++){
				if(map[j][row]) row++;
				else if(row > 1 && map[j][row-1]) row--;
			}
			
			if(i != row){
				check = 0;
				break;
			}
		}
		if(check) flag = 1;
		
		return;
	}
	
	for(int i=y;i<h;i++){
		for(int j=1;j<n;j++){
			if(map[i][j-1] || map[i][j+1] || map[i][j]) continue;
			
			map[i][j] = 1;
			solve(i, cnt+1);
			map[i][j] = 0;
		}
	}
}

int main(){
	cin >> n >> m >> h;
	
	for(int i=0;i<m;i++){
		int a,b;
		cin >> a >> b;
		
		map[a-1][b] = 1;
	}
	
	for(int i=0;i<4;i++){
		depth = i;
		solve(0, 0);
		
		if(flag) {
			cout << depth << endl;
			return 0;
		}
	}
	
	cout << -1 << endl;
}
