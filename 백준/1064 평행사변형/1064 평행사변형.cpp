#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
	double xa,ya,xb,yb,xc,yc;
	cin >> xa >> ya >> xb >> yb >> xc >> yc;
	double a = hypot(xb-xc,yb-yc), b = hypot(xc-xa,yc-ya), c = hypot(xa-xb,ya-yb);
	
	if ((xb-xa)*(yc-ya) == (yb-ya)*(xc-xa)) cout << -1;
	else printf("%.9f\n", (max({a,b,c})-min({a,b,c}))*2);
}
