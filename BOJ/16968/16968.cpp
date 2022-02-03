#include <bits/stdc++.h>
using namespace std;

int main(){
	string str;
	cin >> str;
	
	int len = str.size();
	
	int answer = 1;
	
	if(str[0] == 'c'){
		answer *= 26;
	}
	else{
		answer *= 10;
	}
	
	for(int i=1;i<len;i++){
		if(str[i-1] == str[i]){
			if(str[i] == 'c') answer *= 25;
			else answer *= 9;
		}
		else{
			if(str[i] == 'c') answer *= 26;
			else answer *= 10;
		}
	}
	
	cout << answer << endl;
}
