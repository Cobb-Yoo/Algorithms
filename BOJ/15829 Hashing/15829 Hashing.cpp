#include <iostream>
#include <string>
using namespace std;

int main(){
	int n;
	string s;
	long long answer = 0;
	long long tmp = 1;
	
	cin >> n >> s;
	
	for(int i=0;i<n;i++){
		answer = (answer + tmp*(s[i]-'a'+1))%1234567891;
		tmp = (tmp*31)%1234567891;
	}
	
	cout << answer << endl;
}
