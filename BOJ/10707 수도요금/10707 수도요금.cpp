#include <iostream>
using namespace std;

int main(){
	int a,b,c,d,p;
	cin >> a >> b >> c >> d >> p;
	
	int x = a*p;
	int y;
	
	if(p<=c) y = b;
	else y = b+(p-c)*d;
	
	cout << min(x,y) << endl;
}
