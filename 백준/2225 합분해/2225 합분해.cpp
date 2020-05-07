#include <iostream>
#include <cstring>
using namespace std;

int dp[201][201];

int main(){
	int n,m;
	cin >> n >> m;
	
	memset(dp,0,sizeof(dp));
	for(int i=0;i<=n;i++) dp[1][i] = 1;
	
	for(int i=2;i<=m;i++){
		for(int j=0;j<=n;j++){
			for(int k=0;k<=j;k++){
				dp[i][j] = (dp[i][j] + dp[i-1][j-k]) % 1000000000;
			}
		}
	}
	
	cout << dp[m][n] << endl;
}
