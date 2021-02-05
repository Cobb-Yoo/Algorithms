#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string result[102];
string answer;

void check(string &a, string &b){
	if(a.size() < b.size()) {
		string tmp = b;
		b = a;
		a = tmp;
	}
	else if(a.size()==b.size()){
		if(a < b){
			string tmp = b;
			b = a;
			a = tmp;
		}
	}
}

void add(string b){
	string a = answer;
	string str = "";
	check(a,b);
	
	int a_len = a.size();
	int b_len = b.size();
	
	bool carry = 0;
	for(int i=0;i<a_len;i++){
		int sum;
		if(i < b_len) sum = carry + a[i]-'0' + b[i]-'0';
		else sum = carry + a[i]-'0';
		
		if(sum >= 10){
			carry = 1;
			sum -= 10;
		}
		else carry = 0;
		
		str += to_string(sum);
	}
	
	if(carry) str += '1';
	
	answer = str;
}

void solve(int len){
	answer += '0';
	
	for(int i=0;i<len;i++){
		add(result[i]);
	}
	
	reverse(answer.begin(), answer.end());
}

int main(){
	string a,b;
	cin >> a >> b;
	
	check(a, b);
	
	int a_len = a.size();
	int b_len = b.size();
	
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	
	for(int i=0;i<b_len;i++){
		int carry = 0;
		for(int j=0;j<i;j++) result[i] += '0';
		
		for(int j=0;j<a_len;j++){
			int tmp = carry + (a[j]-'0')*(b[i]-'0');
			
			if(tmp >= 10){
				carry = tmp/10;
				tmp %= 10;
			}
			else carry = 0;
			
			result[i] += to_string(tmp);
		}
		
		if(carry) result[i] += to_string(carry);
	}
	
	solve(b_len);
	
	cout << answer;
}
