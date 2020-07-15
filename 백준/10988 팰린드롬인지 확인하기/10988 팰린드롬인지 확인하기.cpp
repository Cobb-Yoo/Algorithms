#include <iostream>
#include <string>
using namespace std;

int main(){
	string s;
	cin >> s;
	
	int len = s.size();
	
	for(int i=0;i<=len/2;i++){
		if(s[i] != s[len-i-1]){
			cout << 0 << endl;
			return 0;
		}
	}
	
	cout << 1 << endl;
}
