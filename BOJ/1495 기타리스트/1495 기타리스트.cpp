#include <iostream>
#include <cstring>
using namespace std;

int arr[101];
bool dp[101][1001];
int n,s,m;

void solve(int x){	
	for(int i=0;i<=m;i++){
		if(dp[x-1][i]){
			if(i+arr[x] <= m) dp[x][i+arr[x]] = 1;
			if(i-arr[x] >= 0) dp[x][i-arr[x]] = 1;
		}
	}
}

int main(){	
	cin >> n >> s >> m;
	int answer = -1;
	
	memset(dp,0,sizeof(dp));
	for(int i=1;i<=n;i++) cin >> arr[i];
	
	dp[0][s] = 1;
	for(int i=1;i<=n;i++) solve(i);
	
	for(int i=0;i<=m;i++)
		if(dp[n][i])
			answer = i;
	
	cout << answer << endl;
}
