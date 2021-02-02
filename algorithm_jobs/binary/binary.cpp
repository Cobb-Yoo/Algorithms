#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){
	int n; cin >> n;
	
	string str = "";
	
	while(n>0){
		n%2 ? str += "1" : str += "0";
		n/=2;
	}
	reverse(str.begin(), str.end());
	
	cout << str;
}
