#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int main(){
	int n;
	cin >> n;
	
	int time[n+1];
	int money[n+1];
	int dp[n+1];
	
	for(int i=1;i<=n;i++){
		cin >> time[i] >> money[i];
		dp[i] = money[i];
	}
	
	for(int i=2;i<=n;i++){
		for(int j=1;j<i;j++){
			if(i-j >= time[j]) dp[i] = max(dp[i],money[i]+dp[j]);
		}
	}
	
	int MAX = 0;
	
	for(int i=1;i<=n;i++){
		if(i+time[i] <= n+1){
			MAX = max(MAX,dp[i]);
		}
	}
	
	cout << MAX << endl;
	
}
