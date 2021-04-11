#include <bits/stdc++.h>
using namespace std;

int main(){
	string s; cin >> s;
	
	int len = s.size();
	for(int i=0;i<len;i++){
		if('a' <= s[i] && s[i] <= 'z'){
			cout << (char)(s[i]-'a'+'A');
		}
		else{
			cout << (char)(s[i]-'A'+'a');
		}
	}
}
