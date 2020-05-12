#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAX = 500;

int arr[MAX][MAX];
int dp[MAX][MAX]={0};
int option[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
int n;

int dfs(int y, int x){
	if(dp[y][x]) return dp[y][x];
	
	dp[y][x] = 1;
	
	for(int i=0;i<4;i++){
		int ny = y + option[i][0];
		int nx = x + option[i][1];
		
		if(ny<0||ny>=n||nx<0||nx>=n) continue;
		if(arr[y][x] >= arr[ny][nx]) continue;
		dp[y][x] = max(dp[y][x],dfs(ny,nx)+1);
	}
	return dp[y][x];
}

int main(){
	cin >> n;
	
	memset(dp,0,sizeof(dp));
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin >> arr[i][j];
		}
	}
	int m=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			m = max(m,dfs(i,j));
		}
	}
	
	cout << m << endl;
}
