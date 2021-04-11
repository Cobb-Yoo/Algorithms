#include <iostream>
using namespace std;

int main(){
	int answer = 101;
	int sum = 0;
	
	for(int i=0;i<7;i++){
		int num; cin >> num;
		
		if(num&1 == 1) {
			sum += num;
			answer = min(answer, num);
		}
	}
	
	if(!sum) cout << -1 << endl;
	else cout << sum << endl << answer << endl;
}
