#include <iostream>
using namespace std;

int main(){
	int n;
	cin >> n;
	int num = 666;
	int tmp;
	bool a;
	int count=1;
	
	if(n == 1) {}
	else{
		while(num++){
			tmp = num; a = false;
			while(tmp){
				if(tmp%1000 == 666){
					a = true;
					break;
				}
				tmp /= 10;
			}
		
			if(a){
				count++;
				if(count == n) break;
			}
		}
	}
	
	cout << num << endl;

}
