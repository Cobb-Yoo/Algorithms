#include <bits/stdc++.h>
using namespace std;

int n;
string str;
int ans;

int cal(int a, int b, char oper){
	
	switch(oper){
		case '+': return a+b;
		case '-': return a-b;
		case '*': return a*b;
	}
}

void dfs(int idx, int num){
	if(idx > n-1){
		ans = max(ans, num);
		return;
	}
	
	char oper;
	if(idx == 0) oper = '+';
	else oper = str[idx-1];
	
	if(idx+2 < n){
		int tmp = cal(str[idx]-'0', str[idx+2]-'0', str[idx+1]);
		dfs(idx+4, cal(num, tmp, oper));
	}
	
	dfs(idx+2, cal(num, str[idx]-'0', oper));
	
}

int main(){
	cin >> n >> str;
	ans = -987654321;
		
	dfs(0,0);
	
	cout << ans;
}
