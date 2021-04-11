#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const long long MININF = -2e9;
const int MAX = 1000;

long long dp[3][MAX+1][MAX+1];
int arr[MAX+1][MAX+1];
bool visited[MAX+1][MAX+1];
int n,m;

int solve(int dir, int col, int row){
	if(col == n-1 && row == m-1) return arr[col][row];
	
	long long &result = dp[dir][col][row];
	if(result != MININF) return result;
	
	visited[col][row] = true;
	long long candi1= MININF, candi2 =MININF, candi3 = MININF;
	if(row-1 >= 0 && !visited[col][row-1]) candi1 = solve(0,col,row-1);
	if(row+1 < m && !visited[col][row+1]) candi2 = solve(1,col,row+1);
	if(col+1 < n && !visited[col+1][row]) candi3 = solve(2,col+1,row);
	visited[col][row] = false;
	
	return result = arr[col][row] + max({candi1, candi2, candi3});
}

int main(){
	cin >> n >> m;
	
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin >> arr[i][j];
			dp[0][i][j] = dp[1][i][j] = dp[2][i][j] = MININF;
		}
	}
	
	memset(visited,false,sizeof(visited));
	
	cout << solve(0,0,0) << endl;
		
}
