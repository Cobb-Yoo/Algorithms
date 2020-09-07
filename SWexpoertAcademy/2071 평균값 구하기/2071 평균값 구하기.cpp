#include <iostream>
using namespace std;

int main(){
	int t; cin >> t;
	for(int T=1;T<=t;T++){
		float avg=0;
		for(int i=0;i<10;i++) {
			int tmp;
			cin >> tmp;
			
			avg += tmp;
		}
		
		avg /= 10.0;
		avg += 0.5;
		
		cout << "#" << T << " " << (int)avg << endl;
	}
}
