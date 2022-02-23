#include <bits/stdc++.h>
using namespace std;

bool check(string &str){
	int len = str.size();
	
	int a = 0;
	
	for(int i=0;i<len;i++){
		if(str[i] == '{') a++;
		else a--;
		
		if(a < 0) {
			str[i] = '{';
			return 1;
		}
	}
	
	if(a==0) return 0;
	
	
	for(int i=len-1;i>=0;i--){
		if(str[i] == '{') {
			str[i] = '}';
			return 1;
		}
	}
}

int main(){
	string str;
	int idx = 0;
	while(cin >> str){
		idx++;
		
		int num = 0;
		if(str[0] == '-') break;
		
		while(check(str)){
			num++;
		}
		
		cout << idx << ". " << num << endl;
	}
}
