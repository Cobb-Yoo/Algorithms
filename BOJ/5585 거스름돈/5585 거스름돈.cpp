#include <iostream>
using namespace std;

int option[] = {500,100,50,10,5,1};

int main(){
	int n;
	cin >> n; 
	int cnt = 0;
	int i=0;
	
	n = 1000-n;
	
	while(n > 0){
		if(option[i] <= n){
			n -= option[i];
			cnt++;
		}else{
			i++;
			if(i > 5) break;
		}
	}
	
	cout << cnt << endl;
}
