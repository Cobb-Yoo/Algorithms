#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int Max = 200000;
ll arr[Max+1];
ll n; 

ll gcd(ll a, ll b){
	ll r = a % b;
	if (!r)
		return b;
	return gcd(b, r);
}

ll solve(int s, int e){
	ll tmp = arr[s];
	for(int i=s+1;i<=e;i++){
		tmp = gcd(tmp, arr[i]);
	}
	return tmp;
}

ll dfs(int s, int e){
	if(s == e){
		return arr[s];
	}
	
	int mid = (e-s+1)/2 + s;
	int mid2 = (int)(0.5 + (double)(((double)e - s + 1) / 2));
	ll left = dfs(mid, e) + solve(s, mid-1);
	ll right = dfs(s, e-mid2) + solve(e-mid2+1, e);
	return max(left, right);
}

int main(){
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> arr[i];
	}
	
	cout << dfs(0, n-1);
}
