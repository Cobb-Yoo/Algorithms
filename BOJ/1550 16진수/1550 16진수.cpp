#include <string>
#include <iostream>
using namespace std;

int main(){
	string tmp;
	cin >> tmp;
	
	long long answer = 0;
	
	int idx = 0;
	while(idx < tmp.size()){
		answer *= 16;
		
		if(tmp[idx] >= 'A') answer += tmp[idx++] - 'A' + 10;
		else answer += tmp[idx++] - '0';
	}
	
	cout << answer << endl;
}
