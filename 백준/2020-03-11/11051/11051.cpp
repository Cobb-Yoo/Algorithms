#include <iostream>
using namespace std;

int main(){
	int n,k;
	cin >> n >> k;
	
	int arr[n+2][k+2];
	
	for(int i=1;i<=n;i++){
		for(int j=0;j<=k;j++){
			if(j==0) {
				arr[i][j] = 1;
				continue;
			}
			else if(j == i) {
				arr[i][j] = 1;
				break;	
			}
			arr[i][j] = (arr[i-1][j-1] + arr[i-1][j]) % 10007;
		}
	}
	cout << arr[n][k] << endl;
}
