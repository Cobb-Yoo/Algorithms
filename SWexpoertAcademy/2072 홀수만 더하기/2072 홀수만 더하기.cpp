#include <iostream>
using namespace std;

int main(){
	int T; cin >> T;
	
	for(int t=1;t<=T;t++){
		int sum=0;
		for(int i=0;i<10;i++) {
			int tmp;
			cin >> tmp;
			
			if(tmp&1) sum += tmp;
		}
		
		cout << "#" << t << " " << sum << endl;
	}
}
