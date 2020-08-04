#include <iostream>
using namespace std;

int gcd(int a,int b){
	if(a&b==0) return b;
	return gcd(b,a%b);
}

int main(){
	int a,b,c,d,e,f;
	cin >> a >> b >> c >> d;
	
	e = a*c + b*d;
	f = c*d;
	
	int div = gcd(e,f);
	
	cout << e/div << " " << f/div << endl;
}
