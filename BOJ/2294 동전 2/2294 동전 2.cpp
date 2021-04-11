#include <iostream>
#include <cstring>
using namespace std;

const int MAX = 100000;

int main(){
	int n, m;
	cin >> n >> m;
	
	int dp[MAX+1];
	int arr[n+1];
	
	for(int i=1;i<=m;i++) dp[i] = MAX+1;
	dp[0] = 0;
	
	for(int i=1;i<=n;i++) cin >> arr[i];
	
	for(int i=1;i<=n;i++){
		for(int j=arr[i];j<=m;j++){
			dp[j] = min(dp[j],dp[j-arr[i]]+1);
		}
	}
	
	if(dp[m] == MAX+1) cout << -1 << endl;
	else cout << dp[m] << endl;
}
