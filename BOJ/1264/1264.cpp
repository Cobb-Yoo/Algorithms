#include <bits/stdc++.h>
using namespace std;

bool check(char c){
	if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ){
		return 1;
	}
	
	return 0;
}

int main(){
	string str;
	
	while(cin>>str){
		int len = str.size();
		int result = 0;
		
		if(len == 1 && str[0] == '#') break;
		
		for(int i=0;i<len;i++){
			result += check(str[i]);
		}
		
		cout << result << endl;
	}
}
