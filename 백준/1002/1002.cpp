#include <iostream>
using namespace std;

int main(){
	int t;
	int x1,y1,r1,x2,y2,r2;
	int l;
	
	cin >> t;
	
	for(int i=0;i<t;i++){
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
		
		l = (x1-x2) * (x1-x2) + (y1-y2) * (y1-y2);
		int a = (r1 + r2) * (r1 + r2);
		int b = (r2 - r1) * (r2 - r1);
		
		if(l == 0 ) {
			if(b == 0) cout << -1 << endl;
			else cout << 0 << endl;
		}
		else if (l == a || l == b) cout << 1 << endl;
		else if (b < l && l < a) cout << 2 << endl;
		else cout << 0 << endl;
		
	}
}
