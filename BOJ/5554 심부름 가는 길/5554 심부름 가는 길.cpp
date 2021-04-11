#include <iostream>
using namespace std;

int main(){
	int a=0;
	for(int i=0;i<4;i++){
		int tmp; cin >> tmp;
		a += tmp;
	}
	
	cout << a/60 << endl;
	cout << a%60 << endl;
}
