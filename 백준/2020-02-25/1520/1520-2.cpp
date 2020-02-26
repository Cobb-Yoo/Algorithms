#include <iostream>
#include <memory.h>
using namespace std;

int n,m;
int env[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
int arr[501][501];
int visited[501][501];

int f(int a,int b){
	if(a == n-1 && b == m-1) return 1;
	int &result = visited[a][b];
	if(result != -1) return result;
	
	result = 0;
	
	for(int i=0;i<4;i++){
		int x = a + env[i][0];
		int y = b + env[i][1];
		
		if(0<= x && x < n && 0 <= y && y < m && arr[a][b] > arr[x][y]) {
			result += f(x,y);
		}
	}
	
	return result;
}


int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> n >> m;
	
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin >> arr[i][j];
		}
	}
	
    memset(visited, -1, sizeof(visited));
	
	cout << f(0,0) << endl;
}
