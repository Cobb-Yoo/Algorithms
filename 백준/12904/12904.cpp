#include <bits/stdc++.h>
using namespace std;

string s,t;

int main(){
	cin >> s >> t;
	
	bool flag = 0;
	while(1){
		if(t.size() == s.size()){
			if(s == t) flag = 1;
			break;
		}
		char idx = t.back();
		t.pop_back();
		if(idx == 'B') reverse(t.begin(), t.end());
	}
	
	cout << flag;
}
