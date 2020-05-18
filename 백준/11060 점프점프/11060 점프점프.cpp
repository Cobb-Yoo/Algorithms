#include <iostream>
#include <cstring>
using namespace std;

const int MAX = 1000;

int dp[MAX+1];
int n;

int main(){
	memset(dp,0,sizeof(dp));
	cin >> n;
	
	dp[1] = 1;
	for(int i=1;i<=n;i++) {
		int tmp;
		cin >> tmp;
		
		if(dp[i]){
			for(int j=1;j<=tmp && i+j<=1000;j++){
				if(dp[i+j] > dp[i]+1 || dp[i+j]==0) dp[i+j] = dp[i] + 1;
			}
		}
		
	}
	
	if(dp[n]) cout << dp[n]-1 << endl;
	else cout << -1 << endl;
	
}
