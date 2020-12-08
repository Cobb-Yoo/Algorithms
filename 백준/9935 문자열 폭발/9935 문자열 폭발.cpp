#include <iostream>
#include <string>
using namespace std;

const int MAX = 1000000;
char s[MAX+1];

int main(){
	string str;
	string exp;
	
	cin >> str >> exp;
	int len = str.size();
	int top=0;
	
	for(int i=0;i<len;i++){
		s[top++] = str[i];
		
		if(s[top-1] == exp[exp.size()-1]){
			if(top-exp.size() < 0) continue;
			
			bool flag = 1;
			for(int j=0;j<exp.size();j++){
				if(s[top-j-1] != exp[exp.size()-j-1]){
					flag = 0;
					break;
				}
			}
			
			if(flag) top -= exp.size();
		}
	}
	
	if(top <= 0) cout << "FRULA\n";
	else {
		for(int i=0;i<top;i++)	{
			cout << s[i];
		}
	}
}
