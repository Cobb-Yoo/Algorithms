#include <iostream>
#include <cstring>
#define ll long long
using namespace std;

const int MAX = 100;

int arr[MAX+1];
ll dp[MAX+1][21];
int n;

void solve(int x){
	if(x == n) return;
	
	for(int i=0;i<=20;i++){
		if(dp[x-1][i] != 0){
			if(i+arr[x] <= 20) dp[x][i+arr[x]] += dp[x-1][i];
			if(i-arr[x] >= 0) dp[x][i-arr[x]] += dp[x-1][i];
		}
	}
}

int main(){
	cin >> n;
		
	memset(dp,0,sizeof(dp));
		
	for(int i=1;i<=n;i++){
		cin >> arr[i];
	}
	
	dp[1][arr[1]] = 1;
	
	for(int i=2;i<=n;i++){
		solve(i);
	}
	
	cout << dp[n-1][arr[n]] << endl;
}
