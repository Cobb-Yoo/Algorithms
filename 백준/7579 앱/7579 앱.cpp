#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int usingM[101];
int disabled[101];
int dp[101][10001]; //[몇 번째 까지 보았는가][disabled의 누적되는 비용]

int main(){
	int n,m;
	cin >> n >> m;
	
	for(int i=0;i<n;i++) cin >> usingM[i];
	for(int i=0;i<n;i++) cin >> disabled[i];
	
	memset(dp,0,sizeof(dp));
	
	int answer = 987654321;
	
	dp[0][disabled[0]] = usingM[0];
	for(int i=1;i<n;i++){
		for(int j=0;j<=10000;j++){
			if(j-disabled[i] >= 0) dp[i][j] = max(dp[i][j], dp[i-1][j-disabled[i]]+usingM[i]);
			else dp[i][j] = max(dp[i][j],dp[i-1][j]);
			
			if(dp[i][j] >= m) answer = min(answer, j);
		}
	}
	
	cout << answer << endl;
}
