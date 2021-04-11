#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int n;

string add(string a, string b){
	string c="";
	bool flag = 0;
	
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	
	int len = b.size();
	for(int i=0;i<len;i++){
		if(a.size()-1>=i){
			if(flag + a[i]-'0' + b[i]-'0' >= 10){
				c.push_back(flag + a[i]-'0' + b[i] - 10);
				flag = 1;
			}
			else{
				c.push_back(flag + a[i]-'0' + b[i]);
				flag = 0;
			}
		}
		else{
			if(flag + b[i]-'0' >= 10){
				c.push_back(flag + b[i] - 10);
				flag = 1;
			}
			else{
				c.push_back(flag + b[i]);
				flag = 0;
			}
		}
	}
	
	if(flag) c.push_back('1');
	reverse(c.begin(), c.end());
	
	return c;
}

void fibonacci(){
	string a, b, c;
	a = "0";
	b = "1";
	
	if(n == 0) cout << a << endl;
	else if(n == 1) cout << b << endl;
	else{
		for(int i=0;i<n-1;i++){
			c = add(a, b);
			a = b;
			b = c;
		}
		
		cout << c << endl;
	}
}

int main(){
	cin >> n;
	
	fibonacci();
}
