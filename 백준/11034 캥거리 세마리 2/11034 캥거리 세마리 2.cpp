#include <iostream>
using namespace std;

int main(){
	int a, b, c;
	
	while(cin >> a >> b >> c){
		b-a > c - b ? cout << b-a-1 << endl : cout << c-b-1 << endl;
	}
}
