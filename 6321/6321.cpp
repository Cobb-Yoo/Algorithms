#include <bits/stdc++.h>
using namespace std;

int main(){
	int n; cin >> n;
	string str;
	int len;
	
	for(int i=1;i<=n;i++){
		cin >> str;
		len = str.size();
		
		for(int j=0;j<len;j++){
			str[j] = str[j] + 1;
			
			if(str[j] > 'Z') str[j] = 'A';
		}
		
		cout << "String #" << i << endl;
		cout << str << endl << endl;
	}
}
