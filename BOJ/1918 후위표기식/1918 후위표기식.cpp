#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

int main(){
	string str; cin >> str;
	stack<char> s;
	
	int len = str.size();
	bool toggle = 0;
	
	for(int i=0;i<len;i++){
		if(str[i] == '*' || str[i] == '/'){
			if(!s.empty()){
				if(s.top() == '*' || s.top() == '/'){
					cout << s.top();
					s.pop();
				}
			}
			s.push(str[i]);
		}
		else if(str[i] == '+' || str[i] == '-'){
			if(s.empty()) s.push(str[i]);
			else{
				while(!s.empty()){
					if(s.top() == '(') break;
					cout << s.top();
					s.pop();
				}
				s.push(str[i]);
			}
		}
		else if(str[i] == '('){
			s.push(str[i]);
		}
		else if(str[i] == ')'){
			while(s.top() != '('){
				cout << s.top();
				s.pop();
			}
			s.pop();
		}
		else{
			cout << str[i];
		}
	}
	
	while(!s.empty()){
		cout << s.top();
		s.pop();
	}
}
