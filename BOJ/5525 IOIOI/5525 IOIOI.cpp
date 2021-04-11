#include <iostream>
#include <string>
using namespace std;

int main(){
	int n,m;
	string s;
	
	cin >> n >> m >> s;
	int len = s.size();
	int answer = 0;
	
	for(int i=0;i<len;i++){
		if(s[i+1] == 'O' && s[i+2] == 'I'){
			int o = 0;
			while(s[i] == 'I' && s[i+1] == 'O'){
				i += 2;
				o++;
				
				if(s[i] == 'I' && o == n){
					o--;
					answer++;
				}
			}
		}
	}
	
	cout << answer << endl;
}
