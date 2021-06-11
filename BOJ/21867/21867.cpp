#include <bits/stdc++.h>
using namespace std;

int main(){
	int len; cin >> len;
	string str; cin >> str;
	bool flag = 1;
	
	for(int i=0;i<len;i++){
		switch(str[i]){
			case 'J':
			case 'A':
			case 'V':
				continue;
			default:
				flag = 0;
				cout << str[i];
		}
	}
	
	if(flag) cout << "nojava";
}
