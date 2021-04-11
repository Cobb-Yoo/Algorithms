#include <iostream>
#include <cstring>
using namespace std;
const int MAX = 30;

int main(){
	int n;
	cin >> n;
	
	int arr[MAX+1][MAX+1];
	memset(arr,0,sizeof(arr));
	
	for(int i=1;i<=MAX;i++){
		for(int j=0;j<=i;j++){
			if(j == 0 | j == i) arr[i][j] = 1;
			else arr[i][j] = arr[i-1][j-1] + arr[i-1][j];
		}
	}
	
	while(n--){
		int x,y;
		cin >> x >> y;
		
		cout << arr[y][x] << endl;
	}
}
