#include <bits/stdc++.h>
using namespace std;

int main(){
	int n; cin >> n;
	
	string tmp;
	getline(cin, tmp);
	
	for(int i=0;i<n;i++){
		string tmp;
		getline(cin, tmp);
		
		if(tmp[0] >= 'a') tmp[0] = (char)(tmp[0]-'a'+'A');
		
		cout << tmp << endl;
	}
}
