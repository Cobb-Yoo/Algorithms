#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	int n;
	cin >> n;
	
	int arr[n];
	int dp[n];
	int answer=0;
	
	for(int i=0;i<n;i++) {
		cin >> arr[i];
		dp[i] = 0;
	}
	
	for(int i=0;i<n;i++){
		int tmp=0;
		for(int j=0;j<i;j++){
			if(arr[i] > arr[j] && tmp < dp[j])
				tmp = dp[j];
		}
		
		dp[i] = tmp + arr[i];
		answer = max(answer, dp[i]);
	}
	
	cout << answer << endl;
}
