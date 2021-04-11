#include <iostream>
#include <algorithm>
using namespace std;
const int MAX = 10000;

int main(){
	int n;
	cin >> n;
	
	int arr[MAX+1];
	
	for(int i=0;i<= n;i++){
		arr[i] = i;
		for(int j=1;j*j<=i;j++){
			arr[i] = min(arr[i], arr[i-j*j]+1);
		}
	}
	
	cout << arr[n] << endl;
}
