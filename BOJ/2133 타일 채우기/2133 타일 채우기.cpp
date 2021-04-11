#include <iostream>
using namespace std;

int main(){
	int n;
	cin >> n;
	
	if(n&1) cout << 0 << endl;
	else{
		int arr[31] = {0};
		arr[2] = 3;
	
		for(int i=4;i<=n;i+=2){
			arr[i] = 3*arr[i-2] + 2;
			for(int j=i-4;j>0;j-=2){
				arr[i] += 2 * arr[j];
			}
		}
		
		cout << arr[n] << endl;
	}
}
