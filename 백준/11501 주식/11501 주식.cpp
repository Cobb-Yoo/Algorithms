#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int t; cin >> t;
	
	while(t--){
		int n; cin >> n;
		
		vector<ll> v;
		for(int tmp,i=0;i<n;i++){
			cin >> tmp;
			v.push_back(tmp);
		}
		
		reverse(v.begin(), v.end());
		
		int Max = 0;
		ll ans = 0;
		for(int i=0;i<n;i++){
			if(Max < v[i]) Max = v[i];
			else ans += Max - v[i];
		}
		
		cout << ans << "\n";
	}
}
