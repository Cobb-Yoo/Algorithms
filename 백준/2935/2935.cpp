#include <bits/stdc++.h>
using namespace std;

int main(){
	string a,b;
	char c;
	
	cin >> a >> c >> b;
	
	int a_len = a.size()-1;
	int b_len = b.size()-1;
	
	if(c == '+'){
		if(a_len == b_len){
			cout << 2;
			for(int i=0;i<a_len;i++) cout << 0;
		}
		else{
			if(a_len < b_len){
				int tmp = a_len;
				a_len = b_len;
				b_len = tmp;
			}
			
			cout << 1;
			for(int i=0;i<a_len;i++){
				if(a_len-i-1 == b_len) cout << 1;
				else cout << 0;
			}
		}
	}
	else{
		int len = a_len+b_len;
		
		cout << 1;
		for(int i=0;i<len;i++){
			cout << 0;
		}
	}
}
