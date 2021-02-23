#include <bits/stdc++.h>
using namespace std;

int main(){
	string s;
	
	while(getline(cin, s) && s != "END"){
		int len = s.size();
		
		for(int i=len-1;i>=0;i--){
			cout << s[i];
		}
		cout << endl;
	}
}
