#include <iostream>
#define ll long long
using namespace std;

int min(int a, int b){
	if(a > b) return b;
	return a;
}

int main(){
	int n;
	cin >> n;
	
	int dp[n+1]={0};
	
	dp[0] = 0;
	dp[1] = 0;
	
	for(int i=2;i<=n;i++){
		dp[i] = dp[i-1] + 1;
		if(i%2==0) dp[i] = min(dp[i/2]+1,dp[i]);
		if(i%3==0) dp[i] = min(dp[i/3]+1,dp[i]);
		cout << "test i and dp[i] " << i << ' ' << dp[i] <<endl;
	}
	
	cout << dp[n] << endl;
}
