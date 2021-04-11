#include <iostream>
using namespace std;

int main(){
	int n;
	cin >> n;
	
	int m = 0, y = 0;
	
	for(int i=0;i<n;i++){
		int tmp;
		cin >> tmp;
		
		y += (tmp/30 + 1) * 10;
		m += (tmp/60 + 1) * 15;
	}
	
	if(m == y) cout << "Y M " << m << endl;
	else if(m > y) cout << "Y " << y << endl;
	else cout << "M " << m << endl;
}
