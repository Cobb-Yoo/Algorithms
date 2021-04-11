#include <iostream>
#define ll long long
using namespace std;

ll gcd(ll a, ll b){
	if(a%b == 0) return b;
	return gcd(b, a%b);
}

int main(){
	ll a,b;
	cin >> a >> b;
	
	ll len = gcd(a,b);
	
	for(int i=0;i<len;i++) cout << 1;
}
