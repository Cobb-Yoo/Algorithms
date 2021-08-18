#include <bits/stdc++.h>
using namespace std;

const int Max = 20;
int life[Max+1];
int joy[Max+1];
int dp[Max+1][101];
int answer;
int n;

void solve(){
	dp[1][100-life[1]] = joy[1];
	
	for(int i=2;i<=n;i++){
		dp[i][100-life[i]] = joy[i];
		for(int j=100;j>0;j--){
			if(j+life[i] <= 100 && dp[i-1][j+life[i]] != 0){
				dp[i][j] = max(dp[i-1][j+life[i]]+joy[i], dp[i-1][j]);
			}
			else {
				dp[i][j] = max(dp[i-1][j], dp[i][j]);
			}
		}
	}
}

int main(){
	cin >> n;
	
	for(int i=1;i<=n;i++){
		cin >> life[i];
	}
	
	for(int i=1;i<=n;i++){
		cin >> joy[i];
	}
	
	solve();
	
	for(int i=1;i<=100;i++){
		answer = max(answer, dp[n][i]);
	}
	
	cout << answer << endl;
}
