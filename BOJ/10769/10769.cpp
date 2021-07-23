#include <bits/stdc++.h>
using namespace std;

int happy;
int unhappy;
string str;

int main(){
	getline(cin, str);
	int len = str.size();
	
	for(int i=0;i<len;i++){
		if(str[i] == ':'){
			if(i+2 < len){
				if(str[i+1] == '-'){
					if(str[i+2] == '(') unhappy++;
					else if(str[i+2] == ')') happy++;
				}
			}
		}
	}
	
	if(!happy && !unhappy) cout << "none";
	else if(happy == unhappy) cout << "unsure";
	else if(happy > unhappy) cout << "happy";
	else cout << "sad";
}
