#include <iostream>
#include <cstring>
using namespace std;

int dp[10000+1];
int arr[20+1];

int main(){
	int t;
	cin >> t;
	
	while(t--){
		memset(dp,0,sizeof(dp));
		
		int n,m;
		cin >> n;
		
		for(int i=1;i<=n;i++) cin >> arr[i];
		
		cin >> m;
		
		dp[0] = 1;
		for(int i=1;i<=n;i++){
			for(int j=arr[i];j<=m;j++){
				dp[j] += dp[j-arr[i]];
			}
		}
		
		cout << dp[m] << endl;
	}
}
