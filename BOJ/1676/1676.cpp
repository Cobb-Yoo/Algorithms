#include <iostream>
using namespace std;

int main(){
	int n;
	cin >> n;
	int a=0,b=0;
	
	for(int i=2;i<=n;i*=2){
		a += n/i;
	}
	
	for(int i=5;i<=n;i*=5){
		b += n/i;
	}
	
	if(a < b) cout << a << endl;
	else cout << b << endl;
}
