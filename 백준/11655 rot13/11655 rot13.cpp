#include <iostream>
#include <string>
using namespace std;

string rot13(string s){
	int len = s.size();
	
	for(int i=0;i<len;i++){
		if('a'<=s[i]&&s[i]<='z') s[i] = ((s[i]-'a')+13)%26 + 'a';
		else if('A'<=s[i]&&s[i]<='Z') s[i] = ((s[i]-'A')+13)%26 + 'A';
	}
	
	return s;
}

int main(){
	string s;
	getline(cin, s);
	
	cout << rot13(s) << endl;
}
