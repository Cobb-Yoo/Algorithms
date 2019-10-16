#include <iostream>
using namespace std;

int main(){
	int a,b,c;
	int x;
	
	cin >> a >> b >> c;
	if(b == c ||b > c)
		x = -1;
	else
		x = a / (c - b) + 1;
	
	cout << x;
}
