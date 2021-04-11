#include<bits/stdc++.h>
using namespace std;

string s;

void solve(){
	for(char& c : s){
		c -= 3;
		if(c < 'A') c += 26;
	}
}

int main(){
	cin >> s;
	
	solve();
	
	cout << s;
}
