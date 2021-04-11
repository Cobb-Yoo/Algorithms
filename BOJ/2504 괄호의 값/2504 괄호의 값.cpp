#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(){
	int tmp = 1;
	long long answer = 0;
	
	stack<char> st;
	string s; cin >> s;
	
	bool flag = 0;
	for(int i=0;i<s.size();i++){
		if(s[i] == '('){
			tmp *= 2;
			st.push('(');
		}
		else if(s[i] == '['){
			tmp *= 3;
			st.push('[');
		}
		else if(s[i] == ']' && (st.empty() || st.top() != '[')){
			flag = 1;
			break;
		}
		else if(s[i] == ')' && (st.empty() || st.top() != '(')){
			flag = 1;
			break;
		}
		else if(s[i] == ']'){
			if(s[i-1] == '[') answer += tmp;
			st.pop();
			tmp/=3;
		}
		else if(s[i] == ')'){
			if(s[i-1] == '(') answer += tmp;
			st.pop();
			tmp/=2;
		}
		
	}
	
	if(flag || !st.empty()) cout << 0 << endl;
	else cout << answer << endl;
}
