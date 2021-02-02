#include <iostream>
#include <string>
using namespace std;

int n;
string str;

void f(int a){
	string tmp = "";	
	tmp += str + to_string(a) + str;
	str = tmp;
}

int main(){
	cin >> n;
	
	for(int i=1;i<=n;i++) f(i);
	
	cout << str;
}
