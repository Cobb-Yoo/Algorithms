#include <iostream>
using namespace std;

int main(){
	int n; cin >> n;
	
	int *arr = new int[n];
	int ans = 0;
	
	for(int i=0;i<n;i++) cin >> arr[i];
	
	for(int i=0;i<n;i++){
		int cnt = 0;
		for(int j=i+1;j<n;j++){
			if(arr[i] > arr[j]) cnt++;
		}
		
		ans = max(ans, cnt);
	}
	
	cout << ans;
}
