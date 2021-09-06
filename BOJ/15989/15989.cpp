#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int Max = 10000;
ll dp[Max+1][4];
int n;

void init(){
	dp[1][1] = 1;
	dp[2][1] = 1;
	dp[2][2] = 1;
	dp[3][1] = 1;
	dp[3][2] = 1;
	dp[3][3] = 1;
	
	for(int i=4;i<=Max;i++){
		for(int j=1;j<=3;j++){
			int sum = 0;
			
			if(j == 1) dp[i][j] = 1;
			
			for(int k=1;k<=j;k++){
				sum += dp[i-j][k];
			}
			
			dp[i][j] = sum;
		}
	}
}

int main(){
	init();
	int t; cin >> t;
	
	while(t--){
		cin >> n;
		
		cout << dp[n][1]+dp[n][2]+dp[n][3] << endl;
	}
}
