#include <bits/stdc++.h>
using namespace std;

int main(){
	string s;
	cin >> s;
	
	int cnt = 1;
	int len = s.size();
	for(int i=0;i<len;i++){
		if(s[i] == ',') cnt++;
	}
	
	cout << cnt;
}
