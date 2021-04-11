#include <iostream>
#include <list>
#include <string>
using namespace std;

int main(){
	int t; cin >> t;
	
	while(t--){
		list<char> arr;
		list<char>::iterator iter = arr.end();
		
		string str;
		cin >> str;
		
		int len = str.size();
		
		for(int i=0;i<len;i++){
			if(str[i] == '<'){
				if(iter != arr.begin()) iter--;
			}
			else if(str[i] == '>'){
				if(iter != arr.end()) iter++;
			}
			else if(str[i] == '-'){
				if(iter != arr.begin()) iter = arr.erase(--iter);
			}
			else{
				arr.insert(iter, str[i]);
			}
		}
		
		for(list<char>::iterator i = arr.begin();i != arr.end();i++) cout << *i;
		cout << "\n";
		arr.clear();
	}
}
