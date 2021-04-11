#include <iostream>
using namespace std;

int main(){
	int a,b;
	while(cin >> a >> b && a!=0&& b!=0){
		if(!(b%a)){
			cout << "factor\n";
		}
		else if(!(a%b)){
			cout << "multiple\n";
		}
		else{
			cout << "neither\n";
		}
	}
}
