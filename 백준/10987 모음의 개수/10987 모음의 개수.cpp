#include <bits/stdc++.h>
using namespace std;

int main(){
	string s;
	cin >> s;
	
	int len = s.size();
	int answer=0;
	for(int i=0;i<len;i++){
		if(s[i] == 'a' || s[i] == 'e' || s[i] == 'o' || s[i] == 'i' || s[i] == 'u'){
			answer++;
		}
	}
	
	cout << answer << endl;
}
