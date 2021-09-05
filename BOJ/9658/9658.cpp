#include <bits/stdc++.h>
using namespace std;

// 상근 sk, 창영 cy 
// 돌 1,3,4 
// 
const int Max = 1000;
bool dp[Max+1];
int n;

void solve(){
	dp[1] = 0;
	dp[2] = 1;
	dp[3] = 0;
	dp[4] = 1;
	
	for(int i=5;i<=n;i++){
		if(min({dp[i-1], dp[i-3], dp[i-4]})){
			dp[i] = 0;
		}
		else{
			dp[i] = 1;
		}
	}
}

int main(){
	cin >> n;
	
	solve();
	
	if(dp[n]) cout << "SK\n";
	else cout << "CY\n";
}
