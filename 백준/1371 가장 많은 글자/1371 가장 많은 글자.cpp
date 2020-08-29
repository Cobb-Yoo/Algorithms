#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

int arr[50];

int main(){	
	memset(arr,0,sizeof(arr));
	
	string s;
	while(cin >> s && s != ""){ 
		int len = s.size();
	 
		for(int i=0;i<len;i++) {
	 		if('a'<= s[i] && s[i] <= 'z'){
	 			arr[s[i]-'a']++;
			}
		}
	}
	
	int MAX = arr[0];
	for(int i=1;i<26;i++) MAX = max(MAX, arr[i]);
	
	for(int i=0;i<26;i++){
		if(MAX == arr[i])
			cout << (char)(i+'a');
	}
}
