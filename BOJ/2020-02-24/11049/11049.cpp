#include <iostream>
#include <algorithm>
using namespace std;

int dp[501][501];
int arr[501][2];
int result;

int fdp(int a, int b){
	int& ret = dp[a][b];
    if (ret != 0)
        return ret;
	
	if(a == b) return 0;
	
	ret = 987654321;
	
	for(int i=a;i<b;i++){
		ret = min(ret, fdp(a,i) + fdp(i+1, b) + arr[a][0] * arr[i][1] * arr[b][1]);
	}
	return ret;
}

int main(){
	int n;
	cin >> n;
	
	for(int i=0;i<n;i++){
		cin >> arr[i][0] >> arr[i][1];
	}
	
	result = fdp(0,n-1);
	
	cout << result << endl;
}
