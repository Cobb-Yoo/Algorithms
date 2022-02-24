#include <bits/stdc++.h>
using namespace std;

vector<int> failFunc(string sub){
	int len = sub.size();
	vector<int> v(len, 0);
	int j=0;
	
	for(int i=1;i<len;i++){
		while(j>0 && sub[i] != sub[j]){
			j = v[j-1];
		}
		if(sub[i] == sub[j]){
			v[i] == ++j;
		}
	}
	
	return v;
}

bool kmp(string str, string sub){
	vector<int> v = failFunc(sub);
	int j=0;
	
	for(int i=0;i<str.size();i++){
		while(j>0 && str[i] != sub[j]){
			j = v[j-1];
		}
		
		if(str[i] == sub[j]){
			if(j == sub.size()-1) return 1;
			else j++;
		}
	}
	
	return 0;
}

int main(){
	string str, sub;
	cin >> str >> sub;
	
	cout << kmp(str,sub);
}
