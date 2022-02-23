#include <bits/stdc++.h>
#define NUM 2015
using namespace std;

bool visited[26];

int main(){
	int t; cin >> t;
	string str;
	int len;
	
	while(t--){
		memset(visited,0,sizeof(visited));
		
		cin >> str;
		len = str.size();
		
		int tmp = NUM;
		
		for(int i=0;i<len;i++){
			if(!visited[str[i]-'A']){
				tmp -= str[i];
				visited[str[i]-'A'] = 1;
			}
		}
		
		cout << tmp << endl;
	}
}
