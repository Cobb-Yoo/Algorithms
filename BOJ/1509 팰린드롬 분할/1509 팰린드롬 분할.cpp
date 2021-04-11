#include <iostream>
#include <string>
#include <cstring>
using namespace std;

string str;
char s[2501];
int minResult[2501];
int len;

bool palindrome(int start, int end){
	if(start >= end) return 1;
	
	if(s[start] != s[end]) return 0;
	
	return palindrome(start+1, end-1);
}

int getMinLen(){
	minResult[0] = 0;
	
	for(int i=1;i<=len;i++){
		minResult[i] = 987654321;
		for(int j=1;j<=i;j++){
			if(palindrome(j,i)){
				minResult[i] = min(minResult[i], minResult[j-1]+1);
			}
		}
	}
	
	return minResult[len];
}

int main(){
	cin >> str;
	len = str.size();
	
	for(int i=1;i<=len;i++) s[i] = str[i-1];
	
	cout << getMinLen() << endl;
}
