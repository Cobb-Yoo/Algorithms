#include <bits/stdc++.h>
using namespace std;

int main(){
	int t; cin >> t;
	
	while(t--){
		string a,b;
		cin >> a >> b;
		
		int len = a.size();
		
		int x=0,y=0;
		for(int i=0;i<len;i++){
			if(a[i] == '1' && b[i] == '0') x++;
			else if(a[i] == '0' && b[i] == '1') y++;
		}
		
		if(x < y) cout << y << endl;
		else cout << x << endl;
	}
}
