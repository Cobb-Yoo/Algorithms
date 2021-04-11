#include <iostream>
#include <string>
#include <stack> 
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

	string line;
    
	while(getline(cin,line) && line!="."){
		bool flag=1;
		stack<char> st;
		
		for(int i=0;i<line.length();i++){
			if(line[i] == '(' || line[i] == '['){
				st.push(line[i]);
			}
			else if (line[i] == ')'){
				if(!st.empty() && st.top()=='('){
					st.pop();
				}
				else{
					flag = 0;
					break;
				}
			}
			else if (line[i] == ']'){
				if(!st.empty() && st.top()=='['){
					st.pop();
				}
				else{
					flag = 0;
					break;
				}
			}
		}
		
		if(flag) cout << "yes\n";
		else cout << "no\n";
	}
}
