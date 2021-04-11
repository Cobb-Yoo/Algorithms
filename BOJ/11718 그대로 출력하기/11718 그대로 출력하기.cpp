#include <iostream>
#include <string>
using namespace std;

int main(){
	
	string tmp;
	while(getline(cin,tmp) && tmp != ""){
		cout << tmp << endl;
	}
}
