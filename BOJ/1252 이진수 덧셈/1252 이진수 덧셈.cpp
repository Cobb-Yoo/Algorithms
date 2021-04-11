#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main(){
	string s1,s2;
	string answer = "";
	cin >> s1 >> s2;
	
	if(s1.size() < s2.size()){
		string tmp = s1;
		s1 = s2;
		s2 = tmp;
	}
	
	reverse(s1.begin(),s1.end());
	reverse(s2.begin(),s2.end());
	
	bool flag = 0;
	for(int i=0;i<s1.size();i++){
		if(i < s2.size()){
			int a = s1[i]-'0';
			int b = s2[i]-'0';
			
			if(a+b+flag == 3){
				flag = 1;
				answer += '1';
			}
			else if(a+b+flag == 2){
				flag = 1;
				answer += '0';
			}
			else if(a+b+flag == 1){
				flag = 0;
				answer += '1';
			}
			else answer += '0';
		}else{
			int a = s1[i]-'0';
			
			if(a+flag == 2){
				flag = 1;
				answer += '0';
			}
			else if(a+flag == 1){
				flag = 0;
				answer += '1';
			}
			else answer += '0';
		}
	}
	if(flag) answer += '1';
	reverse(answer.begin(),answer.end());
	
	int cnt = 0;
	for(int i=0;i<answer.size();i++){
		if(answer[i] == '0') cnt++;
		else break;
	}
	
	answer.erase(0, cnt);
	if(answer.size() == 0) cout << 0;
	else cout << answer << endl;
}
