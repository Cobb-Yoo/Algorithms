#include <iostream>
#include <string>
using namespace std;

int main(){
	string s;
	
	while(getline(cin, s)){
		if(s=="") break;
		 
		int a=0,b=0,c=0,d=0;
		
		int len = s.size();
		for(int i=0;i<len;i++){
			
			if(s[i] == ' ') d++;
			else if(0<=s[i]-'0' && s[i]-'0'<=9) c++;
			else if('a'<=s[i]) a++;
			else b++;
		}
		cout << a << " " << b << " " << c << " " << d << endl;
	}
}
