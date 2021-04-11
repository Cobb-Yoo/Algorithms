#include <iostream>
#include <algorithm> 
#include <cstring>
using namespace std;

const int MAX = 1000;

int dp[MAX];
int arr[MAX];
int main(){
	int n;
	cin >> n;
	
	for(int i=1;i<=n;i++) cin >> arr[i];
	
	int answer = 0;
	for(int i=1;i<=n;i++){
		dp[i] = 1;
		for(int j=1;j<i;j++){
			if(arr[j] < arr[i] && dp[i] < dp[j]+1)
				dp[i] = dp[j]+1;
		}
		answer = max(answer,dp[i]);
	}
	
	cout << answer << endl;
}
