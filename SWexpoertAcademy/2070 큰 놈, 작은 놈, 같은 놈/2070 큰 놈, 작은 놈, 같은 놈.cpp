#include <iostream>
using namespace std;

int main(){
	int T; cin >> T;
	
	for(int t=1;t<=T;t++){
		int a, b;
		cin >> a >> b;
		
		cout << "#" << t << " ";
		if(a == b) cout << "=";
		else if(a > b) cout << ">";
		else cout << "<";
		
		cout << endl;
	}
}
