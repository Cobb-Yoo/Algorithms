#include <bits/stdc++.h>
using namespace std;

int num;
int answer;

void addNum(){
	answer += num;
	num = 0;
}

void addAnswer(int n){
	num *= 10;
	num += n - '0';
}

int main(){
	string str; cin >> str;
	
	int len = str.size();
	
	for(int i=0;i<len;i++){
		if(str[i] != ',') {
			addAnswer(str[i]);
		}
		else{
			addNum();
		}
	}
	addNum();
	
	cout << answer << endl;
}
