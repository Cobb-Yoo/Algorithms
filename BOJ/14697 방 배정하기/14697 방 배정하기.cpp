#include <iostream>
using namespace std;

int a,b,c;
int total;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int dp[301];
	dp[0] = 1;
	
	cin >> a >> b >> c >> total;
	
	for(int i=1;i<=total;i++){
		if(i >= a){
			if(i >= b){
				if(i >= c) dp[i] = dp[i-a]+dp[i-b]+dp[i-c];
				else dp[i] = dp[i-a]+dp[i-b];
			}
			else dp[i] = dp[i-a];
		}
		else dp[i] = 0;
	}
	
	if(dp[total] == 0) cout << 0;
	else cout << 1;
}
