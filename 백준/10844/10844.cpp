#include <iostream>
#define mm 1000000000
using namespace std;

int main(){
	int n;
	cin >> n;
	
	int arr[101][10] = {0};
	
	for(int i=0;i<10;i++){
		arr[1][i] = 1;
	}
	
	for(int i=2;i<=n;i++){
		for(int j=1;j<10;j++){
			if(j==0){
				arr[i][0] = arr[i-1][1] % mm;
			}
			else if(j==9){
				arr[i][9] = arr[i-1][8] % mm;
			}
			else{
				arr[i][j] = (arr[i-1][j-1] + arr[i-1][j+1]) % mm;
			}
		}
	}
	
	int sum=0;
	
	for(int i=1;i<10;i++){
		sum = (sum + arr[n][i]) % mm;
	}
	
	cout << sum << endl;
}
