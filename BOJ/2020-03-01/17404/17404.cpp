#include <iostream>
#include <algorithm>
using namespace std;
const int INF = 987654321;
int main() {
	int i, j, k, n, arr[1000][3], dp[1001][3];
	cin >> n;
	
	for (i = 0; i < n; i++) {
		for (j = 0; j < 3; j++) {
			scanf("%d", &arr[i][j]);
		}
	}
	
	int ret = INF;
	
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			dp[0][j] = INF;
		}
		dp[0][i] = arr[0][i];

		for (j = 1; j < 1001; j++) {
			for (k = 0; k < 3; k++) {
				dp[j][k] = 0;
			}
		}
	
		for (j = 1; j < n; j++) {
			for (k = 0; k < 3; k++) {
				dp[j][k] = arr[j][k] + min(dp[j - 1][(k + 1) % 3], dp[j - 1][(k + 2) % 3]);
			}
		}
		
		for (j = 0; j < 3; j++) {
			if (j == i) continue;
			ret = min(ret, dp[n - 1][j]);
		}
	}
	cout << ret << endl;
}
