#include<iostream>
using namespace std;

int arr[15][15];
int x, y;

int calc(int n, int m){
	if (n == 1) return 1;
	if (m == 1) return 1;
	
	return arr[n][m] = calc(n - 1, m) + calc(n, m - 1);
}

int main(){
	int n, m, k;
	cin >> n >> m >> k;
	int num = 1;
	
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++){
			if (k == num) x = i, y = j;
			
			arr[i][j] = num++;
		}
	}
	
	if (!k) cout << calc(n, m);
	else cout << calc(x, y)*calc(n - x + 1, m - y + 1);
	
}
