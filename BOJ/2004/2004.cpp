#include <iostream>
#define ll long long
using namespace std;

void cal(ll *a, ll *b, ll n){
	for(ll i=1;i<=n;i*=2){
		*a += n/i;
	}
	for(ll i=1;i<=n;i*=5){
		*b += n/i;
	}
}

int main(){
	ll n,m;
	cin >> n >> m;
	
	ll a_2=0;
	ll a_5=0;
	ll b_2=0;
	ll b_5=0;
	ll c_2=0;
	ll c_5=0;
	
	cal(&a_2,&a_5,n);
	cal(&b_2,&b_5,m);
	cal(&c_2,&c_5,n-m);
	
	ll a,b;
	
	a = a_2 - (b_2 + c_2);
	b = a_5 - (b_5 + c_5);
	
	a<b? cout << a : cout << b;
	cout << endl;
}
