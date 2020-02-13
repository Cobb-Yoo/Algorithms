#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int n,m,C;
bool arr[51][51];
bool check[51][51];
int fff[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

void f(int y, int x){
	check[y][x] = 1;
	
	for(int i=0;i<4;i++){
		int nx = x + fff[i][1];
		int ny = y + fff[i][0];
		
		if(0 <= nx && nx <= m && 0 <= ny && ny <= n && !check[ny][nx] && arr[ny][nx]){
			check[ny][nx] = 1;
			f(ny,nx);
		}
	}
}

void init(){
	for(int i=0;i<51;i++){
		for(int j=0;j<51;j++){
			arr[i][j] = check[i][j] = 0;
		}
	}
}

int main(){
	int T;
	cin >> T;
	
	while(T--){
		
		init();
		cin >> n >> m >> C;
		int cnt = 0;
		
		for(int i=0;i<C;i++){
			int node1;
			int node2;
			
			cin >> node1 >> node2;
			arr[node1][node2] = 1;
		}
		
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(!check[i][j] && arr[i][j]){
					f(i,j);
					cnt++;
				}
			}
		}
		
		cout << cnt << endl;
	}
}
