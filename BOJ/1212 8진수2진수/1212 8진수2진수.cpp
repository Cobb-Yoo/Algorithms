#include <iostream>
#include <string>
using namespace std;

void firstnum(int n){
	if(n == 1) cout << 1;
	else if(n < 4){
		for(int i=2;i>=1;i/=2){
			if(n&i) cout << 1;
			else cout << 0;
		}
	}
	else{
		for(int i=4;i>=1;i/=2){
			if(n&i) cout << 1;
			else cout << 0;
		}
	}
}

int main(){
	string s;
	cin >> s;
	
	int len = s.size();
	
	if(len == 1 && s[0] == '0') {
		cout << '0';
		return 0;
	}
	
	firstnum(s[0]-'0');
	for(int i=1;i<len;i++){
		int n = s[i]-'0';
		
		for(int j=4;j>=1;j/=2){
			if(n&j) cout << 1;
			else cout << 0;
		}
	}	
}
