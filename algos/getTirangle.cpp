#include <iostream>
using namespace std;

int main(){
	int a1,a2,a3;
	int b1,b2,b3;
	
	cout << "first tirangle = ";
	cin >> a1 >> b1;
	cout << "second tirangle = ";
	cin >> a2 >> b2;
	cout << "third tirangle = ";
	cin >> a3 >> b3;
	
	cout << abs((a1*b2+a2*b3+a3*b1)-(a1*b3+a2*b1+a3*b2)) / 2 << endl;
}
