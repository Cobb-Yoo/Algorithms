#include <iostream>
using namespace std;

int main(){
	int n;
	cin >> n;
	
	int arr[1001];
	
	arr[1] = 1;
	arr[2] = 3;
	
	for(int i=3;i<1001;i++){
		arr[i] = (arr[i-2]*2 + arr[i-1])%10007;
	}
	
	cout << arr[n] << endl;
}
