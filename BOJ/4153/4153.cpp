#include <iostream>
using namespace std;

int main(){
	int a,b,c;
	
	while(cin >> a >> b >> c){
		if(a == 0 && b == 0 && c== 0) break;
		
		a = a * a;
		b = b * b;
		c = c * c;
		
		if(c == a+b || a==b+c || b == a+c) cout << "right\n";
		else cout << "wrong\n";
	}
}
