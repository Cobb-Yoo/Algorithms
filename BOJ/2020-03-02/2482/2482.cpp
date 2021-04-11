#include <iostream>
#include <cstring>
using namespace std;

const int MAX = 1000;

int arr[MAX+1][MAX+1];

int main(){
	int n,m;
	cin >> n >> m;
	
	for(int i=1;i<=3;i++) arr[i][1] = i;
	
	for(int i=4;i<=n;i++){
		int len = i/2;
		
		for(int j=1;j<=len;j++){
			if(j == 1) arr[i][j] = i;
			else arr[i][j] = (arr[i-2][j-1] + arr[i-1][j]) % 1000000003 ;
		}
	}
	
	cout << arr[n][m] << endl;
}
