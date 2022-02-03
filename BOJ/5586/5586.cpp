#include <bits/stdc++.h>
using namespace std;

int main(){
	int joi=0, ioi=0;
	string str;
	cin >> str;
	
	int len = str.size();
	
	for(int i=0;i<len-2;i++){
		if(str[i] == 'J'){
			if(str[i+1] == 'O'){
				if(str[i+2] == 'I'){
					joi++;
					i+=1;
				}
			}
			else continue;
		}
		else if(str[i] == 'I'){
			if(str[i+1] == 'O'){
				if(str[i+2] == 'I'){
					ioi++;
					i+=1;
				}
			}
			else continue;
		}
		else continue;
	}
	
	cout << joi << endl << ioi << endl;
}
