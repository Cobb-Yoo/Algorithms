#include <iostream>
using namespace std;

int main(){
	int n;
	cin >> n;
	
	int tmp=2;
	
	while(n!=0){
		if(n==1){
			break;
		}
		
		if(n%tmp==0){
			
			cout << tmp << endl;
			n /= tmp;
		}
		else tmp++;
	}
}
