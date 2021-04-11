#include <iostream>
#include <string>
using namespace std;

int main(){	
	string s;
	int n;
	int result = 0;
	int len = s.size();
	
	cin >> s >> n;
	
	for(int i=0;i<s.size();i++){
		if('0' <= s[i] && s[i] <= '9'){
			result *= n;
			result += s[i]-'0';
		}
		else{
			result *= n;
			result += s[i]-'A'+10;
		}
	}
	
	cout << result << '\n';
}
