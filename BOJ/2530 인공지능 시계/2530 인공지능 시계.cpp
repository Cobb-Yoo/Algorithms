#include <iostream>
using namespace std;

int main(){
	int h,m,s;
	cin >> h >> m >> s;
	
	int n;
	cin >> n;
	
	int tmp;
	
	tmp = (s+n)/60;
	s = (s+n)%60;
	
	int tmp2 = (m+tmp)/60;
	m = (m+tmp)%60;
	
	h = (tmp2+h)%24;
	
	cout << h << " " << m << " " << s << endl;
}
