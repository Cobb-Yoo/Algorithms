#include <iostream>
#include <cstring>
using namespace std;

int main(){
	int n;
	cin >> n;
	
	int arr[2][100001];
	
	while(n--)	{
		memset(arr,0,sizeof(arr));
		
		int len;
		cin >> len;
		
		for(int i=0;i<2;i++){
			for(int j=2;j<len+2;j++){
				cin >> arr[i][j];
			}
		}
		
		for(int j=2;j<len+2;j++){
			for(int i=0;i<2;i++){
				if(!i) arr[i][j] += max(arr[i+1][j-2],arr[i+1][j-1]);
				else arr[i][j] += max(arr[i-1][j-2],arr[i-1][j-1]);
			}
		}
		
		cout << max(arr[0][len+1],arr[1][len+1]) << endl;
	}
}
