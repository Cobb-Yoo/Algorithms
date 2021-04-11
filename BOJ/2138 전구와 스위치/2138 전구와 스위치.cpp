#include <bits/stdc++.h>
using namespace std;

int answer = 987654321;
string copys;
string s,result;
int n;

void push(int idx){
    if (idx > 0)
        copys[idx - 1] = (copys[idx - 1] == '0') ? '1' : '0';
        
    copys[idx] = (copys[idx] == '0') ? '1' : '0';
    
    if (idx < n - 1)
        copys[idx + 1] = (copys[idx + 1] == '0') ? '1' : '0';
}

void solve(int idx, int cnt){
	if(idx == n-1){
		bool flag = 1;
		for(int i=0;i<n;i++){
			if(copys[i] != result[i]){
				flag = 0;
				break;
			}
		}
		
		if(flag) answer = min(answer, cnt);
		
		push(idx);
		flag = 1;
		
		for(int i=0;i<n;i++){
			if(copys[i] != result[i]){
				flag = 0;
				break;
			}
		}
		
		if(flag) answer = min(answer, cnt+1);
		return;
	}
	
	if(copys[idx-1] == result[idx-1]) solve(idx+1, cnt);
	push(idx);
	
	if(copys[idx-1] == result[idx-1]) solve(idx+1, cnt+1);
	push(idx);
}

int main(){
	cin >> n;
	cin >> s >> result;
	
	copys = s;
	solve(1,0);
	
	copys = s;
	push(0);
	solve(1,1);
	
	if(answer == 987654321) cout << -1;
	else cout << answer;
}
