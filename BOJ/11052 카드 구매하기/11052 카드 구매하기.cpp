#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int main(){
	int n;
	cin >> n;
	
	int arr[n+1];
	int dp[1001];
	memset(dp,0,sizeof(dp));
	
	for(int i=1;i<=n;i++){
		cin >> arr[i];
	}
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			dp[i] = max(dp[i],dp[i-j]+arr[j]);
		}
	}
	
	cout << dp[n];
}
