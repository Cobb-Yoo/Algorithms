#include <iostream>
using namespace std;

int main(){
	
	int n;
	cin >> n;
	int arr[1000001];
	
	arr[0]=0;
	arr[1]=1;
	arr[2]=2;
	
	for(int i=3;i<=n;i++){
		arr[i] = arr[i-1] + arr[i-2];
		arr[i]%=15746;
	}
	
	cout << arr[n] << endl;
}
