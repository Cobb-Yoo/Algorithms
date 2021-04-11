#include <iostream>
#include <cstring>
using namespace std;
bool arr[101][101];
bool brr[101][101];

int main(){
	int n;
	cin >> n;
	
	memset(arr,0,sizeof(arr));
	memset(brr,0,sizeof(brr));
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin >> arr[i][j];
		}
	}
	
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(k&1){
					if(arr[i][j]) brr[i][j] = 1;
					else if(arr[i][k] && arr[k][j]) brr[i][j] = 1;
				}
				else{
					if(brr[i][j]) arr[i][j] = 1;
					else if(brr[i][k] && brr[k][j]) arr[i][j] = 1;
				}
			}
		}
	}
	
	if(n&1){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				cout << brr[i][j] << " ";
			}
			cout << endl;
		}
	}
	else{
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				cout << arr[i][j] << " ";
			}
			cout << endl;
		}
	}
}
