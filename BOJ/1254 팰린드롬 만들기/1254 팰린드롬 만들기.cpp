#include <iostream>
#include <string>
using namespace std;

int main(){
	string s; cin >> s;
	
	int len = s.size();
	int r = 1000-len;
	
	for(int i=0;i<=r;i++){
		int j;
		for(j=i;j<len;j++){
			if(s[j] != s[len-j-1+i]) break;
		}
		
		if(j==len){
			cout << i+len << endl;
			return 0;
		}
	}
	
	
}
