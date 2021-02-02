#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){
	string a,b,str="";
	cin >> a >> b;
	
	if(a.size() < b.size()){
		string tmp = b;
		b = a;
		a = tmp;
	}
	else if(a.size() == b.size()){
		if(a < b){
			string tmp = b;
			b = a;
			a = tmp;
		}
	}
	
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	
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
	
	reverse(str.begin(), str.end());
	
	cout << str;
}
