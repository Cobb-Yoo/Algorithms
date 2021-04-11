#include <iostream>
#include <string>
using namespace std;

int main(){
	int n; cin >> n;
	
	string s; cin >> s;
	
	int cnt=1;
	int l = 0;
	for(int i=0;i<n;i++){
		if(s[i]=='S') cnt++;
		else {
			l++;
			
			if(l==2){
				l = 0;
				cnt++;
			}	
		}
	}
	
	if(l==1) cnt++;
	
	cout << min(cnt, n);
}
