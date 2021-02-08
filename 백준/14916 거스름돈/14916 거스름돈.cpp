#include <iostream>
using namespace std;

int main(){
	int n; cin >> n;
	int five=0;
	int two=0;
	
	five = n/5;
	n %= 5;
	two = n/2;
	n %= 2;
	
	while(n){
		if(five) {
			five--;
			n+= 5;
		}
		else break;
				
		two += n/2;
		n %= 2;
	}
	
	if(n) cout << -1;
	else cout << five+two;
}
