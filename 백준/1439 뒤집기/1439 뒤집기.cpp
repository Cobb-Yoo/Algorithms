#include <iostream>
#include <string>
using namespace std;

int main(){
	string s; cin >> s;
	
	int len = s.size()-1;
	int a=1;
	int b=0;
	
	bool flag=0; 
	for(int i=0;i<len;i++){
		if(s[i] == s[i+1]) continue;
		else {
			flag ? a++ : b++;
			flag = !flag;
		}
	}
	
	if(a > b) cout << b;
	else cout << a;
	
}

