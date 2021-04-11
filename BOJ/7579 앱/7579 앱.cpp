#include <iostream>
using namespace std;

int n,m,sum;
int arr[101];
int brr[101];
int dp[10001];

int main(){
	cin >> n >> m;
	
	for(int i=0;i<n;i++) cin >> arr[i];
	for(int i=0;i<n;i++) {
		cin >> brr[i];
		sum += brr[i];
	}
	
	for(int i=0;i<n;i++){
		for(int j=sum;j>=brr[i];j--){
			dp[j] = max(dp[j], dp[j-brr[i]]+arr[i]);
		}
	}
	
	int i;
	for(i=0;i<sum && dp[i]<m;i++);
	cout << i;
}
