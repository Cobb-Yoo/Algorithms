#include <iostream>
using namespace std;

int arr[30001];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n; cin >> n;
	
	int ans = 0;
	
	for(int i=0;i<n;i++) cin >> arr[i];
	
	for(int i=0;i<n;i++){
		int cnt = 0;
		for(int j=i+1;j<n;j++){
			if(arr[i] > arr[j]) cnt++;
			else break;
		}
		
		ans = max(ans, cnt);
	}
	
	cout << ans;
}
