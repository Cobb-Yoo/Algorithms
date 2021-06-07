#include <iostream>
#define ll long long
using namespace std;

const int f = 1000000007;

ll n;


struct M{
	ll data[2][2];
};

M multiply(M a, M b){
	M c;
	c.data[0][0] = (a.data[0][0]*b.data[0][0]+a.data[0][1]*b.data[1][0])%f;
	c.data[0][1] = (a.data[0][0]*b.data[1][0]+a.data[0][1]*b.data[1][1])%f;
	c.data[1][0] = (a.data[1][0]*b.data[0][0]+a.data[1][1]*b.data[1][0])%f;
	c.data[1][1] = (a.data[1][0]*b.data[1][0]+a.data[1][1]*b.data[1][1])%f;
	
	return c;
}

M divide(M a, ll num){
	if(num > 1){
		a = divide(a, num/2);
		a = multiply(a, a);
		if(num&1){
			M b;
			b.data[0][0] = 1; b.data[0][1] = 1;
			b.data[1][0] = 1; b.data[1][1] = 0;
			
			a = multiply(a,b);
		}
	}
	
	return a;
}

ll fibo(ll num){
	M a;
	a.data[0][0] = 1; a.data[0][1] = 1;
	a.data[1][0] = 1; a.data[1][1] = 0;
	a = divide(a, num);
	
	return a.data[0][1];
}

int main(){
	cin >> n;
	
	if(n == 0) cout << 0 << endl;
	else cout << fibo(n) << endl;
}
