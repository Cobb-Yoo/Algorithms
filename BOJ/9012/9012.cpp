#include <iostream>
#include <string>
using namespace std;

int top=0;

void cal(string line){
	int len = line.length();
	for(int i=0;i<len;i++){
		if(line[i]=='(') top++;
		else top--;
		
		if(top < 0) {
			cout << "NO\n";
			return;
		}
	}
	
	if(!top) cout << "YES\n";
	else cout << "NO\n";
}

int main(){
	int n;
	cin >> n ;
	string line;
	
	for(int i=0;i<n;i++){
		top=0;
		cin >> line;
		cal(line);
	}
}
