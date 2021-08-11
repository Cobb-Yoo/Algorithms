#include <bits/stdc++.h>
using namespace std;

const int Max = 1500000;
int dp[Max+1];
pair<int,int> arr[Max+1];
int n, answer;

void solve(){
	int cur = 0;
	for(int i=0;i<=n;i++){
		cur = max(cur, dp[i]);
		int t = arr[i].first;
		int p = arr[i].second;
		
		if(i+t > n) continue;
		
		dp[i+t] = max(cur+p, dp[i+t]);
	}
	
	answer = cur;
}

int main(){
	cin >> n;
	
	for(int t,p,i=0;i<n;i++){
		cin >> t >> p;
		arr[i] = {t,p};
	}
	
	solve();
	
	
	cout << answer << endl;
}
