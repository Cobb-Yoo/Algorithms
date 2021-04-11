#include <iostream>
using namespace std;

int main(){
	long long s;
	cin >> s;
	
	long long answer = 1;
	
	while(1){
		if(s == (answer*(answer + 1))/ 2) break;
		else if(s < (answer*(answer + 1))/ 2) {
			answer--;
			break;
		}
		answer++;
	}
	
	cout << answer << endl;
}
