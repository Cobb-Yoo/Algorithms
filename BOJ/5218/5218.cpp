#include <bits/stdc++.h>
using namespace std;

int main(){
	int a = 0, b = 0;
	int len; cin >> len;
	string str; cin >> str;
	
	for(int i=0;i<len;i++){
		if(str[i] == 'A') a++;
		else b++;
	}
	
	if(a < b) cout << 'B';
	else if(b < a) cout << 'A';
	else cout << "Tie";
}
