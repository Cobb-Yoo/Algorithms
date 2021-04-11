#include <iostream>
using namespace std;

int main(){
	int n,k;
	int arr[101];
	int data[10001] = {0};
	
	cin >> n >> k;
	
	for(int i=1;i<=n;i++){
		cin >> arr[i];
	}
	
	data[0] = 1;
	
	
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            if (j >= arr[i]) {
                data[j] += data[j-arr[i]];
            }
        }
    }
	
	cout << data[k] << endl;	
}


