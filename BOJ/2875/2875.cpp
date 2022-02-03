#include <bits/stdc++.h>
using namespace std;

int main(){
	int len;
	string str;
	
	vector<int> v;
	
	for(int j=1;j<=5;j++){
		cin >> str;
		len = str.size();
		
		for(int i=0;i<len-2;i++){
			if(str[i] == 'F' && str[i+1] == 'B' && str[i+2] == 'I'){
				v.push_back(j);
				break;
			}
		}
	}
	
	len = v.size();
	if(!len) cout << "HE GOT AWAY!";
	else {
		for(int i=0;i<len;i++){
			cout << v[i] << " ";
		}
	}
}
