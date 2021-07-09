#include <bits/stdc++.h> 
using namespace std;

char transfort(string s){
	int num = 0;
	
	if(s[2] == '1') num += 1;
	if(s[1] == '1') num += 2;
	if(s[0] == '1') num += 4;
	
	
	return num+'0';
}

int main(){
	string str; cin >> str;
	string answer = "";
	string tmp = "";
	int len = str.size();
	
	switch(len%3){
		case 0:
			for(int i=0;i<len;i+=3){
				answer += transfort(str.substr(i, 3));
			}
			break;
		case 1:
			tmp = "00" + str.substr(0,1);
			answer += transfort(tmp);
			
			for(int i=1;i<len;i+=3){
				answer += transfort(str.substr(i, 3));
			}
			break;
		case 2:
			tmp = "0" + str.substr(0,2);
			answer += transfort(tmp);
			
			for(int i=2;i<len;i+=3){
				answer += transfort(str.substr(i, 3));
			}
			break;
	}
	
	cout << answer << endl;
}

