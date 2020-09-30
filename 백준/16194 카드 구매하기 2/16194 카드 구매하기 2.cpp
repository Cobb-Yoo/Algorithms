#include <iostream>
using namespace std;

int arr[1001];
int n;

int main(){
	cin >> n;
	
	for(int i=1;i<=n;i++) cin >> arr[i];
	
	for(int i=2;i<=n;i++){
		for(int j=1;j<=i;j++){
			arr[i] = min(arr[i], arr[i-j]+arr[j]);
		}
	}
	
	cout << arr[n] << endl;
}
