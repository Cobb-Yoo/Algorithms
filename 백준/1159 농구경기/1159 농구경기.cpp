#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int arr[26];

int main(){
	int n; cin >> n;
	
	for(int i=0;i<n;i++){
		string s;
		cin >> s;
		
		arr[s[0]-'a']++;
	}
	
	bool flag = 1; 
	for(int i=0;i<26;i++){
		if(arr[i] >= 5) {
			cout << (char)(i+'a');
			flag = 0;
		}
	}
	
	if(flag) cout << "PREDAJA\n";
}
