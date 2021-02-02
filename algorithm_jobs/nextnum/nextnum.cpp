#include <iostream>
using namespace std;

int main(){
	float a,b,c;
	
	while(cin >> a >> b >> c){
		if(!a && !b && !c) break;
		
		if(b == (a+c)/2) cout << "AP " << c + b - a << endl;
		else cout << "GP " << c * b / a << endl;
	}
}
