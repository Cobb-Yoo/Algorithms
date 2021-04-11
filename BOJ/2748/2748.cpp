#include <iostream>
using namespace std;

int main(){
	int n;
	cin >> n;
	double a = 0;
	double b = 1;
	double c;
	
	if(n == 0) cout << a;
	else if(n == 1) cout << b;
	else{
		for(int i=2;i<=n;i++){
			c = a + b;
			a = b;
			b = c;
		}
	
		printf("%lld\n",c);
	}
}
