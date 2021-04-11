#include <iostream>
#include <cstring>
using namespace std;

const int MAX = 1000;

int main(){
	int n;
	cin >> n;
	
	int arr[MAX+1][10];
	memset(arr,0,sizeof(arr));
	
	for(int i=0;i<10;i++) arr[1][i] = 1;
	
	for(int i=2;i<=n;i++){
		for(int j=0;j<10;j++){
			for(int k=j;k<10;k++){
				arr[i][j] += arr[i-1][k];
				arr[i][j] %= 10007;
			}
		}
	}
	
	int answer =0;
	
	for(int i=0;i<10;i++) {
		answer += arr[n][i];
		answer %= 10007;	
	}
	
	cout << answer << endl;
}
