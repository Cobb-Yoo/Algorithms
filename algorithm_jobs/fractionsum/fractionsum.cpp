#include <iostream>
using namespace std;

int gcd(int a,int b){
    if(a%b == 0) return b;
    return gcd(b,a%b); 
}

int lcm(int a,int b){
    return a*b/gcd(a,b);
}

int main(){
	int a,b,c,d;
	int e,f;
	cin >> a >> b >> c >> d;
	
	e = a*d+b*c;
	f = b*d;
	
	int g = 0;
	if(e < f) g = gcd(f,e);
	else g = gcd(e,f);
	
	if(g) cout << e/g << " " << f/g;
	else cout << e << " " << f;
	
}
