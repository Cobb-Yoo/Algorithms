#include <bits/stdc++.h>
#define ll long long
using namespace std;

int arr[500001];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n; cin >> n;
	
	ll len = 0;
	for(int i=0;i<n;i++){
		cin >> arr[i];
		len += arr[i];
	}
	
	ll ans=0;
	for(int i=0;i<n;i++){
		len -= arr[i];
		ans += len*arr[i];
	}
	
	cout << ans << endl;
}
