#include <iostream>
#include <cstring>
using namespace std;

const int MAX = 1000;

int n, m;
int map[MAX][MAX];
pair<int,int> answer;

void function(int cnt, int y, int x, int dir){
	if(cnt == 0) return;
	if(cnt == m){
		answer.first = y;
		answer.second = x;
	}
	
	if(dir == 0){
		int i;
		for(i=y;i<n;i++){
			if(map[i][x] == -1) {
				if(cnt == m){
					answer.first = i+1;
					answer.second = x+1;
				}
				map[i][x] = cnt--;
			}
			else break;
		}
		function(cnt, i-1, x+1, 1);
	}
	else if(dir == 1){
		int j;
		for(j=x;j<n;j++){
			if(map[y][j] == -1) {
				if(cnt == m){
					answer.first = y+1;
					answer.second = j+1;
				}
				map[y][j] = cnt--;
			}
			else break;
		}
		function(cnt, y-1, j-1, 2);
	}
	else if(dir == 2){
		int i;
		for(i=y;i>=0;i--){
			if(map[i][x] == -1){
				if(cnt == m){
					answer.first = i+1;
					answer.second = x+1;
				}
				map[i][x] = cnt--;
			} 
			else break;
		}
		function(cnt, i+1, x-1, 3);
	}
	else if(dir == 3){
		int j;
		for(j=x;j>=0;j--){
			if(map[y][j] == -1){
				if(cnt == m){
					answer.first = y+1;
					answer.second = j+1;
				}
				map[y][j] = cnt--;
			} 
			else break;
		}
		function(cnt, y+1, j+1, 0);
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	memset(map,-1,sizeof(map));
	
	cin >> n >> m;
	
	function(n*n, 0, 0, 0);
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout << map[i][j] << " ";
		}
		cout << "\n";
	}
	cout << answer.first << " " << answer.second << endl;
}
