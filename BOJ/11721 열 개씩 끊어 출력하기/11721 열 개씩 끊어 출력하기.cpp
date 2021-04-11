#include <iostream>
#include <string>
using namespace std;

int main(){
	string s;
	cin >> s;
	
	int len = s.size();
	
	for(int i=0;i<len;i++){
		if(i!=0 && i%10 == 0) {
			cout << endl << s[i];
		}
		else cout << s[i];
	}
}
