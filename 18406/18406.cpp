#include <bits/stdc++.h>
using namespace std;

int main(){
	int len;
	string str;
	
	cin >> str;
	len = str.size();
	
	int a = 0;
	int b = 0;
	
	for(int i=0;i<len/2;i++){
		a += str[i]-'0';
		b += str[i+len/2]-'0';
	}
	
	if(a == b) cout << "LUCKY";
	else cout << "READY";
}
