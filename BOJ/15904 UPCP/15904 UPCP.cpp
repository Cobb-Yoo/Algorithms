#include <iostream>
#include <string>
using namespace std;

int main(){
	string str;
	getline(cin, str);
	
	char option[] = {'U','C','P','C'};
	int len = str.size();
	
	int idx = 0;
	for(int i=0;i<len;i++){
		if(str[i] == option[idx]) idx++;
		if(idx == 4) break;
	}
	
	if(idx == 4) cout << "I love UCPC";
	else cout << "I hate UCPC";
}
