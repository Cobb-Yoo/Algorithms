#include <iostream>
#include <string>
using namespace std;

int main(){
	string s;
	
	while(cin >> s && s != "0"){
		bool flag = 1;
		int len = s.size();
		
		for(int i=0;i<len;i++){
			if(s[i] != s[len-1-i]) {
				flag = 0;
				break;
			}
		}
		
		if(flag) cout << "yes\n";
		else cout << "no\n";
	}
}
