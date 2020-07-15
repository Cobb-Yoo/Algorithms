#include <iostream>
using namespace std;

int main(){
	int answer = 0;
	int tmp;
	
	while(cin >> tmp){
		if(answer + tmp >= 100){
			if(100-answer >= answer+tmp - 100) answer = answer+tmp;
			break;
		}
		answer += tmp;
	}
	
	cout << answer << endl;
}
