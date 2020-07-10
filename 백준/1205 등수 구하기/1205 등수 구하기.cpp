#include <iostream>
using namespace std;

int main(){
	int n,score,p;
	cin >> n >> score >> p;
	
	int arr[n+1];
	
	for(int i=1;i<=n;i++) cin >> arr[i];
	
	if(n==p && arr[n] >= score) cout << -1 << endl;
	else {
		for(int i=1;i<=n;i++) {
			if(arr[i] <= score) {
				cout << i << endl;
				return 0;
			}
		}
		cout << n+1 << endl;
	}
} 
