#include <iostream>
using namespace std;

int main(){
	for(int i=0;i<3;i++){
		int cnt = 4;
		for(int j=0;j<4;j++){
			int tmp; cin >> tmp;
			cnt -= tmp;		
		}
		
		if(cnt == 1) cout << "A\n";
		else if(cnt == 2) cout << "B\n";
		else if(cnt == 3) cout << "C\n";
		else if(cnt == 4) cout << "D\n";
		else cout << "E\n";
	}
}
