#include <bits/stdc++.h>
using namespace std;

string result[1000];

void swap(string &a, string &b){
	if(a.size() < b.size() || (a.size() == b.size() && a < b)){
		string tmp = a;
		a = b;
		b = tmp;
	}
}

string add(string aa, string bb){
	string a = aa, b = bb;
	int a_len, b_len;
	
	swap(a,b);
	string str="";
	
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	
	a_len = a.size();
	b_len = b.size();
	
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
	
	reverse(str.begin(), str.end());
	
	return str;
}

string sub(string aa, string bb){
	string a = aa, b = bb;
	int a_len, b_len;
	
	bool flag = 0;
	string str="";
	
	if((a.size() == b.size() && a < b) || a.size() < b.size()) flag = 1;
	
	swap(a,b);
	
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	
	a_len = a.size();
	b_len = b.size();
	
	bool carry = 0;
	for(int i=0;i<a_len;i++){
		int minus;
		if(i < b_len) {
			if(a[i]-'0' - b[i]-'0' - carry < 0) {
				minus = 10 + a[i]-'0' - b[i]+'0' - carry;
				carry = 1;
			}
			else {
				minus = a[i]-'0' - b[i]+'0' - carry;
				carry = 0;
			}
		}
		else {
			if(a[i]-'0' - carry < 0) {
				minus = 10 + a[i]-'0'-carry;
				carry = 1;
			}
			else{
				minus = a[i]-'0'-carry;
				carry = 0;
			}
		}
		
		str += to_string(minus);
	}
	
	while(str.back() == '0') str.pop_back();
	if(flag) str += '-';
	
	reverse(str.begin(), str.end());
	
	return str;
}

string mul(string aa, string bb){
	string a = aa, b = bb;
	int a_len, b_len;
	
	swap(a,b);
	
	a_len = a.size();
	b_len = b.size();
	
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
	
	string ans = "";
	for(int i=0;i<b_len;i++) ans = add(ans, result[i]);
	
	reverse(ans.begin(), ans.end());
	
	return ans;
}

int main(){
	string a,b;
	cin >> a >> b;
	
	cout << add(a,b) << endl;
	cout << sub(a,b) << endl;
	cout << mul(a,b) << endl;
}
