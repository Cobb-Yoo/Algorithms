#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int dp[101][100001];

int main(){
	int n,v;
	cin >> n >> v;
	
	vector<vector<int>> arr;
	
	vector<int> val;
	val.push_back(0);
	val.push_back(0);
	arr.push_back(val);
	
	for(int i=1;i<=n;i++){
		int a,b;
		cin >> a >> b;
		vector<int> val;
		
		val.push_back(a);
		val.push_back(b);
		
		arr.push_back(val);
	}
	
	sort(arr.begin(),arr.end());
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=v;j++){
			if(arr[i][0] > j) dp[i][j] = dp[i-1][j];
			else dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - arr[i][0]] + arr[i][1]);
		}
	}
	
	cout << dp[n][v] << endl;
}
