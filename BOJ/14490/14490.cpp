#include <bits/stdc++.h> 
using namespace std;
// 제발 커밋이 되어라 
int gcd(int a, int b){
    if(b == 0) return a;
	else return gcd(b, a%b);
}

int main(){
	string str; cin >> str;
	int idx;
	int num, num1, num2;
	string str1 = "", str2 = "";
	
	int len = str.size();
	
	for(int i=0;i<len;i++){
		if(str[i] == ':') {
			idx = i;
		}
	}
	
	str1 = str.substr(0, idx);
	str2 = str.substr(idx+1, len);
	
	num1 = stoi(str1);
	num2 = stoi(str2);
	
	if(num1 < num2) num = gcd(num1, num2);
	else num = gcd(num2, num1);
	
	cout << num1/num << ":" << num2/num << endl;
}
