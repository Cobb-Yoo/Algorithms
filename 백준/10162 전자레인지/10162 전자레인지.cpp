#include <iostream>
using namespace std;

int main(){
	int a=0,b=0,c=0;
	int n;
	cin >> n;
	
	if(n % 10) cout << -1;
	else{
		a=n/300;
		n%=300;
		b=n/60;
		n%=60;
		c=n/10;
		
		cout << a << " " << b << " " << c << endl;
	}
}
