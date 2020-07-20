#include <iostream>
#include <string>
using namespace std;

int main(){
	string s;
	cin >> s;
	
	if(s[0] == '0'){
		if(s[1] == 'x'){
			int answer = 0;
			
			for(int i=2;i<s.size();i++){
				answer *= 16;
				if(s[i] >= 'a') answer += s[i]-'a'+10;
				else answer += s[i]-'0';
			}
			cout << answer << endl;
		}
		else{
			int answer = 0;
			
			for(int i=1;i<s.size();i++){
				answer *= 8;
				answer += s[i]-'0';
			}
			cout << answer << endl;
		}
	}
	else{
		cout << s << endl;
	}
}
