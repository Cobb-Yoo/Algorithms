#include <iostream>
#include <algorithm>
#define ll long long
#define ld long double
using namespace std;

int main(){
	ll n,l,w,h;
	cin >> n >> l >> w >> h;
	
	double left=0,right;
	right = max({l,w,h});
	
	for(int i=0;i<10000;i++){
		ld mid = (left+right)/2;
		if((ll)(l/mid) * (ll)(w/mid) * (ll)(h/mid) >= n) left = mid;
		else right = mid;
	}
	
	printf("%.10lf",right);
}
