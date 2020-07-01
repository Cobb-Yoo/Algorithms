#include <iostream> 
#include <string>
#include <cstring>
using namespace std;

bool option['Z'+1];

void init(){
	memset(option, 0, sizeof(option));
	string data = "CAMBRIDGE";
	
	for(int i=0;i<data.size();i++) option[data[i]] = 1;
}

int main(){
	string str;
	cin >> str;
	
	string answer = "";
	init();
	
	for(int i=0;i<str.size();i++) if(!option[str[i]]) answer += str[i];
	
	cout << answer << endl;	
}
