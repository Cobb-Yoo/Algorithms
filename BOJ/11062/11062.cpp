#include <bits/stdc++.h>
using namespace std;

const int Max = 1000;
int dp[Max+1][Max+1];
int arr[Max+1];

int solve(int left, int right, int cnt){
	if(left > right) return 0;
	if(dp[left][right]) return dp[left][right];
	
	if(cnt&1){
		return dp[left][right] = max(arr[left]+solve(left+1, right, cnt+1), arr[right]+solve(left, right-1, cnt+1));
	}
	else{
		return dp[left][right] = min(solve(left+1, right, cnt+1), solve(left, right-1, cnt+1));
	}
}

int main(){
	int t; cin >> t;
	
	while(t--){
		memset(dp, 0, sizeof(dp));
		
		int n; cin >> n;
		
		for(int tmp,i=0;i<n;i++){
			cin >> arr[i];
		}
		solve(0, n-1, 1);
		cout << dp[0][n-1] << endl;
	}
}
