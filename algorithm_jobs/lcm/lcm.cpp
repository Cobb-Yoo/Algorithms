#include <iostream>
#define ll long long
using namespace std;

ll gcd(ll a,ll b){
    if(a%b == 0) return b;
    return gcd(b,a%b); 
}

ll lcm(ll a,ll b){
    return a*b/gcd(a,b);
}

int main(){
	ll a,b;
	cin >> a >> b;
	
	if(a < b) a^=b^=a^=b;
	
	cout << lcm(a,b);
}
