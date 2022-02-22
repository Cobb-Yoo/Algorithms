#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int Max = 200001;
int psum[Max];
int n, k;

map<int, ll> Map;

int main(){
	cin >> n >> k;
	ll ans = 0;
	int num;
	
	for(int i=1;i<=n;i++){
		cin >> num;
		psum[i] = psum[i-1] + num;
	}
	
	for(int i=1;i<=n;i++){
		if(psum[i] == k){
			ans++;
		}
		
		ans += Map[psum[i]-k];
		
		Map[psum[i]]++;
	}
	
	cout << ans;
}
