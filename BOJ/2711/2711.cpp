#include <bits/stdc++.h>
using namespace std;

int main(){
	int t; cin >> t;
	
	while(t--){
		int n; cin >> n;
		string str; cin >> str;
		
		str.erase(str.begin()+n-1);
		
		cout << str << endl;
	}
}
