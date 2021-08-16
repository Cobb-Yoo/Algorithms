#include <bits/stdc++.h>
using namespace std;

long long dp[36];
int n;

int main(){
	cin >> n;
	
	dp[0] = 1;
	
	for(int i=1;i<=n;i++){
		long long tmp = 0;
		 
		if(i&1){ // È¦¼ö 
			for(int j=0;j<i/2;j++){
				tmp += dp[i-1-j]*dp[j];
			}
			
			dp[i] = tmp*2 + dp[i/2]*dp[i/2];
		}
		else{ // Â¦¼ö 
			for(int j=0;j<i/2;j++){
				tmp += dp[i-1-j]*dp[j];
			}
			
			dp[i] = tmp*2;
		}
	}
	
	cout << dp[n];
}
