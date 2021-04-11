#include <bits/stdc++.h>
using namespace std;

bool arr[26];
string words[50];
int n, k;
int result = 0;

void solve(int idx, int cnt){
	if(cnt == k){
		int tmp=0;
		
		for(int i=0;i<n;i++){
			bool flag = 1;
			
			for(int j=0;j<words[i].size();j++){
				if(!arr[words[i][j]-'a']){
					flag = 0;
					break;
				}
			}
			
			if(flag) tmp++;
		}
		
		result = max(tmp, result);
		return;
	}
	
	for(int i=idx;i<26;i++){
		if(!arr[i]){
			arr[i] = 1;
			solve(i, cnt+1);
			arr[i] = 0;
		}
	}
}

int main(){
	cin >> n >> k;
	
	if(k < 5) {
		cout << 0;
		return 0;
	}
	else if(k >= 26){
		cout << n;
		return 0;
	}
	
	k -= 5;
	
	for(int i=0;i<n;i++){
		cin >> words[i];
		
		words[i] = words[i].substr(4, words[i].size());

		for(int j=0;j<4;j++) words[i].pop_back();
	}
	
	arr['a'-'a'] = 1;
	arr['c'-'a'] = 1;
	arr['i'-'a'] = 1;
	arr['n'-'a'] = 1;
	arr['t'-'a'] = 1;
	
	solve(0, 0);
	
	cout << result << endl;
}
