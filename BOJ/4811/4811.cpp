#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll dp[31][31];

void init(){
	for(int j=0;j<=30;j++){
		for(int i=0;i<=30;i++){
			if(j > i) continue;
			
			if(j==0) dp[i][j] = 1;
			else dp[i][j] = dp[i-1][j] + dp[i][j-1];
		}
	}
}

int main(){
	init();
	
	int n;
	
	while(cin >> n && n != 0){
		cout << dp[n][n] << endl;
	}
}
