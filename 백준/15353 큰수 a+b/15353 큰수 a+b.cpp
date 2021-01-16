#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){
	string a, b; cin >> a >> b;
	string answer="";
	
	if(b.size() > a.size()){
		string tmp = b;
		b = a;
		a = tmp;
	}
	
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
		
	int len = a.size();
	int b_len = b.size();
	bool flag=0;
	
	for(int i=0;i<len;i++){
		int tmp;
		
		if(b_len > i) tmp = a[i]-'0'+b[i]-'0'+flag;	
		else tmp = a[i]-'0'+flag;
		
		if(tmp >= 10) {
			tmp -= 10;
			flag = 1;
		}
		else flag = 0;
			
		answer += tmp+'0';
		
	}
	
	if(flag) answer += '1';
	
	reverse(answer.begin(), answer.end());
	
	cout << answer << endl;
}
