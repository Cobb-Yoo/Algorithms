#include <iostream>
using namespace std;

int main(){
	int n;
	cin >> n;
	int i;
	
	if(n!=1){
		for(i=1;;i++){
			if(2+3*i*(i-1) <= n && n <= 1 + 3*i*(i+1)){
				break;
			}
		}
		
		i++;
	}
	else
		i=1;
	
	cout << i;
}
