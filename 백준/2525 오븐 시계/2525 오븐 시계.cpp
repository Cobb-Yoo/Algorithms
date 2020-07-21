#include <iostream>
using namespace std;

int main(){
	int a,b,c;
	cin >> a >> b >> c;
	
	int tmp = b+c;
	
	a += tmp/60;
	tmp %= 60;
	
	cout << a << " " << tmp << endl;
}
