#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){
	int n;
	string buffer;
	
	cin >> n;
	getline(cin, buffer); // 버퍼지우기 
	
	
	while(n--){
		string s;
		string tmp = "";
		
		getline(cin, s);
		int len = s.size();
		
		for(int i=0;i<len;i++){
			if(s[i] == ' '){
				reverse(tmp.begin(),tmp.end());
				cout << tmp << " ";
				tmp.clear();
			}
			else {
				tmp += s[i];
			}
		}
		
		reverse(tmp.begin(),tmp.end());
		cout << tmp << endl;
	}
}
