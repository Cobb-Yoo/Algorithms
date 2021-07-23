#include <bits/stdc++.h>
using namespace std;

int alpA[26];
int alpB[26];

bool isAnagrams(string a, string b){
	memset(alpA,0,sizeof(alpA));
	memset(alpB,0,sizeof(alpB));
	
	for(auto i:a) alpA[i-'a']++;
	for(auto i:b) alpB[i-'a']++;
	
	for(int i=0;i<26;i++){
		if(alpA[i] != alpB[i]) return 1;
	}
	
	return 0;
}

int main(){
	int t; cin >> t;
	
	while(t--){
		string a,b;
		cin >> a >> b;
		
		
		cout << a << " & " << b <<" are ";
		
		if(isAnagrams(a,b)) cout << "NOT ";
		
		cout << "anagrams.\n";
	}
}
