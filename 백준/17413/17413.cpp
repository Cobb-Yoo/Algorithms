#include <bits/stdc++.h>
using namespace std;

int main(){
	string s;
	getline(cin, s);
	
	int len = s.size();
	string tmp = "";
	bool flag = 0;
	for(int i=0;i<len;i++){
		if(s[i] == '<'){
			reverse(tmp.begin(), tmp.end());
			cout << tmp;
			tmp = '<';
			flag = 1;
		}
		else if(s[i] == '>'){
			cout << tmp << '>';
			tmp = "";
			flag = 0;
		}
		else if(s[i] == ' '){
			if(flag){
				tmp += ' ';
				continue;
			}
			reverse(tmp.begin(), tmp.end());
			cout << tmp << ' ';
			tmp = "";
		}
		else tmp += s[i];
	}
	
	if(tmp != "") {
		reverse(tmp.begin(), tmp.end());
		cout << tmp;
	}
}
