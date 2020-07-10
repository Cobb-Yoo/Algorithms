#include <iostream>
using namespace std;

int main(){
	double a,b,c;
	cin >> a >> b >> c;
	
	double n1 = a*b/c;
	double n2 = a/b*c;
	
	if(n1 > n2) cout << (long long)n1;
	else cout << (long long)n2;
}
