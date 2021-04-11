#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){
	int n; cin >> n;
	int tmp;
	
	while(n){
		tmp = n;
		bool flag = 1;
		while(tmp > 0){
			if(!(tmp%10==4 || tmp%10==7)){
				flag = 0;
				break;
			}
			
			tmp /= 10;
		}
		
		if(flag) {
			cout << n;
			return 0;
		}
		n--;
	}
}
