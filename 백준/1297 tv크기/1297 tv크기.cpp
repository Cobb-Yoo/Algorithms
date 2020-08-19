#include <iostream>
#include <cmath>
using namespace std;

int main(){
	int a,b,c;
	cin >> a >> b >> c;
	
	float x = a / sqrt(b*b+c*c);
	
	b = b*x;
	c = c*x;
	
	cout << b << " " << c;
}
