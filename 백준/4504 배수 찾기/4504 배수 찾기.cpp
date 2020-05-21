#include <iostream>
using namespace std;

int main(){
	int n;
	cin >> n;
	
	int tmp;
	while(cin >> tmp && tmp){
		if(tmp%n) cout << tmp << " is NOT a multiple of " << n <<".\n";
		else cout << tmp << " is a multiple of " << n <<".\n";
	}
}
