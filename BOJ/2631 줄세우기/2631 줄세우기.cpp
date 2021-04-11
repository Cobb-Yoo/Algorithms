#include <iostream>
using namespace std;

int arr[201];
int dp[201] = {0};

int main(){
	int n;
	cin >> n;

	for(int i=1;i<=n;i++){
		cin >> arr[i];
	}
	
	int len = 0;
	for(int i=1;i<=n;i++){
		int tmp = 0;
		for(int j=0;j<i;j++){
			if(arr[j] < arr[i]) tmp = max(dp[j], tmp);
		}
		
		dp[i] = tmp + 1;
		len = max(len, dp[i]);
	}
	
	
	
	cout << n - len << endl;
}
