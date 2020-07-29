#include <iostream>
#include <string>
using namespace std;

int main(){
	int n;
	string s;
	long long answer = 0;
	int tmp = 1;
	
	cin >> n >> s;
	
	for(int i=0;i<n;i++){
		answer += tmp*(s[i]-'a'+1);
		tmp*=31;
	}
	
	cout << answer << endl;
}
