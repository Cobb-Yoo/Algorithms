#include <iostream>
#include <string>
using namespace std;

int main(){
	string s;
	getline(cin, s);
	int len = s.size();
	
	for(int i=0;i<len;i++){
		if(s[i] == ' ') continue;
		cout << s[i];
	}
}
