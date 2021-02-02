#include <iostream>
using namespace std;

int main(){
	int n; cin >> n;
	int idx=2;
	
	while(n>1){
		if(n%idx == 0) {
			cout << idx << endl;
			n /= idx;
		}
		else idx++;
	}
}
