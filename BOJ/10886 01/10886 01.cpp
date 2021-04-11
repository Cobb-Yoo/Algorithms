#include <iostream>
using namespace std;

int main(){
	int n; cin >> n;
	int cnt = 0;
	bool tmp;
	
	for(int i=0;i<n;i++) {
		cin >> tmp;
		
		if(tmp) cnt++;
	}
	
	if(n/2 < cnt) cout << "Junhee is cute!";
	else cout << "Junhee is not cute!";
}
