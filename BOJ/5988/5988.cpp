#include <bits/stdc++.h>
using namespace std;

int main(){
	int n; cin >> n;
	int len;
	
	string str;
	
	while(n--){
		cin >> str;
		
		len = str.length();
		
		int answer = str[len-1]-'0';
		
		if(answer&1) cout << "odd" << endl;
		else cout << "even" << endl;
	}
}
