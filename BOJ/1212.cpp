#include <bits/stdc++.h>
using namespace std;

int main(){
	int n; cin >> n;
	
	string str = "";
	
	while(n > 0){
		if(n&1) str += '1';
		else str += '0';
		
		n>>=1;
	}
	
	reverse(str.begin(), str.end());
	
	cout << str << endl;
}
