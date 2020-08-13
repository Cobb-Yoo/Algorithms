#include <iostream>
#include <string>
#include <cstring>
#include <stack>
using namespace std;

const int MAX = 1000;

int lcs[MAX+1][MAX+1];
string firstString, secondString;
int first_len;
int second_len;
int answer_len;

void getLen(){
	for(int i=1;i<=first_len;i++){
		for(int j=1;j<=second_len;j++){
			lcs[i][j] = max(lcs[i-1][j], lcs[i][j-1]);
		
			if(firstString[i-1] == secondString[j-1]) lcs[i][j] = lcs[i-1][j-1]+1;
		}
	}
	
	answer_len = lcs[first_len][second_len];
	cout << answer_len << endl;
}

void getString(){
	stack<char> s;
	
	int i,j;
	i = first_len;
	j = second_len;
	
	
	while(i>=1 && j>=1){
		if(lcs[i][j] == lcs[i-1][j]) i--;
		else if(lcs[i][j] == lcs[i][j-1]) j--;
		else {
			s.push(firstString[i-1]);
			i--;
			j--;
		}
	}
	
	while(!s.empty()){
		cout << s.top();
		s.pop();
	}
}

int main(){
	memset(lcs,0,sizeof(lcs));
	
	cin >> firstString >> secondString;
	first_len = firstString.size();
	second_len = secondString.size();
	
	getLen();
	if(answer_len != 0) getString();
}
