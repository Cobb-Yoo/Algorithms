#include <iostream>
#include <cstring>
#define ll long long
using namespace std;

int n;
ll dp[101][101];
int arr[101][101];

ll path(int x, int y){
	if(x == n-1 && y == n-1) return 1;
	if(dp[x][y] != -1) return dp[x][y];
	dp[x][y] = 0;
	
	if(x != n-1 && x+arr[x][y] < n) dp[x][y] += path(x+arr[x][y],y);
	if(y != n-1 && y+arr[x][y] < n) dp[x][y] += path(x,y+arr[x][y]);

	return dp[x][y];
}

int main(){
	cin >> n;
	
	memset(dp,-1,sizeof(dp));
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin >> arr[i][j];
		}
	}
	
	cout << path(0,0) << endl;
}
