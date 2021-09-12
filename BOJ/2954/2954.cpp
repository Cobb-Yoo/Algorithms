#include <bits/stdc++.h>
using namespace std;

char option[5] = {'a','e','i','o','u'};

bool checkOption(char c){
	for(int i=0;i<5;i++){
		if(c == option[i]){
			return 1;
		}
	}
	return 0;
}

int main(){
	string str;
	string answer="";
	
	getline(cin, str);
	int len = str.size();
	
	for(int i=0;i<len;){
		if(checkOption(str[i])) {
			answer += str[i];
			i += 3;
		}
		else {
			answer += str[i];
			i+= 1;
		}
	}
	
	cout << answer << endl;
}
