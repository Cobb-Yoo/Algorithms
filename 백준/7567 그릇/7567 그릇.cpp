#include <iostream>
#include <string>
using namespace std;

int main(){
	string s;
	cin >> s;
	
	int len = s.size();
	int high=10;
	
	for(int i=1;i<len;i++){
		if(s[i-1] == s[i]) high += 5;
		else high += 10;
	}
	
	cout << high << endl;
}
