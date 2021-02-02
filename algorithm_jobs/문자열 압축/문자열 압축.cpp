#include <iostream>
#include <string>
using namespace std;

int main(){
	string s; cin >> s;
	int len = s.size();
	
	for(int cnt=1,i=0;i<len;i++){
		if(s[i] == s[i+1]){
			cnt++;
		}
		else{
			if(cnt == 1) cout << s[i];
			else cout << cnt << s[i];
			cnt=1;
		}
	}
}
