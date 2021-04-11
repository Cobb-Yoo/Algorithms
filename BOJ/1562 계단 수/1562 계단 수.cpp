#include <iostream>
using namespace std;

const int mod = 1000000000;
int n;
int dp[101][10][1024];

int main(){
	cin >> n;
	
	for(int i=1;i<=9;i++) dp[1][i][1<<i] = 1;
	
	for(int i=2;i<=n;i++){
		for(int j=0;j<=9;j++){
			for(int k=1;k<=1023;k++){
				if(j==0)
					dp[i][j][k|(1<<0)] = (dp[i][0][k|(1<<0)] + dp[i-1][1][k]) % mod;
				else if(j==9)
					dp[i][j][k|(1<<9)] = (dp[i][9][k|(1<<9)] + dp[i-1][8][k]) % mod;
				else{
					dp[i][j][k|(1<<j)] = (dp[i][j][k|(1<<j)] + dp[i-1][j-1][k]) % mod;
					dp[i][j][k|(1<<j)] = (dp[i][j][k|(1<<j)] + dp[i-1][j+1][k]) % mod;
				}
			}
		}
	}
	
	int answer = 0;
	for(int i=0;i<=9;i++){
		answer = (answer + dp[n][i][1023])%mod;
	}
	
	cout << answer << endl;
}
