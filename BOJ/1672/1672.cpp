#include <bits/stdc++.h>
using namespace std;

// A : 0
// G : 1
// C : 2
// T : 3
char graph[4][4] = {{'A','C','A','G'},{'C','G','T','A'},{'A','T','C','G'},{'G','A','G','T'}};

char check(char a, char b){
	int na, nb;
	
	if(a == 'A') na = 0;
	else if(a == 'G') na = 1;
	else if(a == 'C') na = 2;
	else na = 3;
	
	if(b == 'A') nb = 0;
	else if(b == 'G') nb = 1;
	else if(b == 'C') nb = 2;
	else nb = 3;
	
	return graph[na][nb];
}

int main(){
	int len;
	string str;
	
	cin >> len >> str;
	
	for(int i=len-2;i>=0;i--){
		str[i] = check(str[i], str[i+1]);
	}
	
	cout << str[0];
}
