#include <bits/stdc++.h>
using namespace std;

int main(){
	int t; cin >> t;
	string str;
	
	
	while(t--){
		cin >> str;
		
		cout << str[0] << str[str.size()-1] << endl;
	}
}
