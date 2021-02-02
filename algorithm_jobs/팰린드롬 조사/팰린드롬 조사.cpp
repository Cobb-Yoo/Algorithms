#include <iostream>
#include <string>
using namespace std;

int main(){
	string s; cin >> s;
	int len = s.size();
	
	for(int i=0;i<len;i++){
		if(s[i] != s[len-1-i]){
			cout << "NO\n";
			return 0;
		}
	}
	
	cout << "YES";
}
