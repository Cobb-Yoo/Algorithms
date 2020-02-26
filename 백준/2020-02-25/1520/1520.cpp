#include <iostream>
#include <memory.h>
using namespace std;

int n,m;
int env[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
int arr[501][501];
int visited[501][501];

int f(int a,int b){
	if(visited[a][b] != -1) return visited[a][b];
	if(a < 0 || n <= a || b < 0 || m <= b) return 0;
	if(a == 0 && b == 0) return 1;
	
	visited[a][b] = 0;
	
	for(int i=0;i<4;i++){
		int x = a + env[i][0];
		int y = b + env[i][1];
		
		if(arr[a][b] < arr[x][y]) {
			visited[a][b] += f(x,y);
		}
	}
	
	return visited[a][b];
}


int main(){
	cin >> n >> m;
	
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin >> arr[i][j];
		}
	}	
	
	memset(visited, -1, sizeof(visited));
	
	cout << f(n-1,m-1) << endl;
}
