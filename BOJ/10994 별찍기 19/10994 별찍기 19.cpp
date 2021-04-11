#include <iostream>
#include <cstring>
using namespace std;

const int MAX = 400+1;

char map[MAX][MAX];

void solve(int cnt, int y, int x){
	if(cnt == 0) return;
	
	int len = (cnt-1)*4+1;
	
	for(int i=0;i<len;i++){
		map[y][x+i] = '*';
		map[y+i][x] = '*';
		map[y+i][x+len-1] = '*';
		map[y+len-1][x+i] = '*';
	}
	
	solve(cnt-1, y+2, x+2);
}

int main(){
	
	int n; cin >> n;
	
	solve(n, 0, 0);
	
	int len = (n-1)*4+1;
	
	for(int i=0;i<len;i++){
		for(int j=0;j<len;j++){
			map[i][j] == '*' ? cout << "*" : cout << " ";
		}
		if(i==len-1) break;
		cout << "\n";
	}
}
