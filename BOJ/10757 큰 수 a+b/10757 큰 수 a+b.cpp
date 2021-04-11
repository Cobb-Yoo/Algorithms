#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string add(string s1, string s2){
	string added(max(s1.size(), s2.size()),'0');
	
	int len = added.size();
	int len1 = s1.size();
	int len2 = s2.size();
	
	bool carry = 0;
	
	for(int i=0;i<len;i++){
		int tmp = 0;
		
		if(i < len1) tmp += s1[len1-i-1]-'0';
		if(i < len2) tmp += s2[len2-i-1]-'0';
		tmp += carry;
		
		if(tmp > 9) {
			carry = 1;
			tmp -= 10;
		}
		else carry = 0;
		
		added[len-i-1] = tmp + '0';
	}
	
	if(carry) added.insert(added.begin(),'1');
	
	return added;
}

int main(){
	string s1,s2;
	cin >> s1 >> s2;
	
	cout << add(s1,s2) << endl;
}
