#include <iostream>
#include <string>
using namespace std;

int main(){
	string a,b,result="";
	
	cin >> a >> b;
	
	if(a.size() < b.size() || (a.size() == b.size() && a < b)){
		string tmp = a;
		a = b;
		b = tmp;
	}
	
	int a_len = a.size();
	int b_len = b.size();
	
	for(int i = a_len-1;i>=0;i--){
		bool carry = 0;
		
		string tmp = "";
		for(int j = b_len-1;j>=0;j--){
			
		}
		
		if(carry) tmp += '1'
	}
}
