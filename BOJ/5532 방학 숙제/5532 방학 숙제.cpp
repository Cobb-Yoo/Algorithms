#include <iostream>
using namespace std;

int main(){
	int l,a,b,c,d;
	cin >> l >> a >> b >> c >> d;
	
	int math = l-(a/c);
	int lang = l-(b/d);
	
	if(a%c) math-=1;
	if(b%d) lang-=1;
	
	cout << min(math,lang) << endl;
}
