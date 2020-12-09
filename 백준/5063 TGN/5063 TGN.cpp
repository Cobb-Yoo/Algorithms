#include <iostream>
using namespace std;

int main(){
	int n; cin >> n;
	
	while(n--){
		int a,b,c;
		cin >> a >> b >> c;
		
		if(a > b-c) cout << "do not advertise\n";
		else if(a < b-c) cout << "advertise\n";
		else cout << "does not matter\n";
	}
}
