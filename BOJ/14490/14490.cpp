#include <bits/stdc++.h> 
using namespace std;

int gcd(int a, int b){
    
    if(b == 0){
        return a;
    }else{
        return gcd(b, a%b);
    }
}

int main(){
	string str; cin >> str;
	
	string str1 = "", str2 = "";
	
	int len = str.size();
	
	int idx;
	for(int i=0;i<len;i++){
		if(str[i] == ':') {
			idx = i;
		}
	}
	
	str1 = str.substr(0, idx);
	str2 = str.substr(idx+1, len);
	
	int num1, num2;
	num1 = stoi(str1);
	num2 = stoi(str2);
	
	cout << num1 << " " << num2 << endl;
}
