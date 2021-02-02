#include <iostream>
#include <string>
using namespace std;

void swap(string s){
	int len = s.size();
	
	for(int i=0;i<len;i++){
		if('a'<=s[i] && s[i]<='z'){
			cout << (char)(s[i]-'a'+'A');
		}
		else if('A'<=s[i] && s[i]<='Z'){
			cout << (char)(s[i]-'A'+'a');
		}
		else{
			cout << s[i];
		}
	}
}

int main(){
	string s;
	getline(cin, s);
	
	swap(s);
}
