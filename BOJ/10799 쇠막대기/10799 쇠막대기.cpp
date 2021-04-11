#include <iostream>
#include <string>
using namespace std;

int main(){
	string s;
	cin >> s;
	
	int len = s.size();
	
	int cnt = 0;
	int answer = 0;
	for(int i=0;i<len;i++){
		if(s[i] == '(') cnt++;
		else{
			cnt--;
			if(s[i-1] == '(') answer += cnt;
			else answer++;
		}
	}
	
	cout << answer << endl;
}
