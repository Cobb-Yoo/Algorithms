#include <iostream>
#include <string>
using namespace std;

char arr[8] = {'E','S','T','J','I','N','F','P'};

int main(){
	string s;
	cin >> s;
	string answer="";
	
	for(int i=0;i<4;i++){
		int idx;
		for(idx=0;idx<8;idx++) {
			if(s[i] == arr[idx]) break;
		}
		
		answer += arr[(idx+4)%8];
	}
	
	cout << answer << endl;
}
