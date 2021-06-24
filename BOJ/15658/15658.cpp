#include <bits/stdc++.h>
using namespace std;

int oper[4];
int arr[11];
int n;
int Min = INT_MAX;
int Max = INT_MIN;

int operation(int num, int op, int idx){
	if(op == 0) num += arr[idx];
	else if(op == 1) num -= arr[idx];
	else if(op == 2) num *= arr[idx];
	else if(op == 3) {
		if(num < 0){
			num *= -1;
			num /= arr[idx];
			num *= -1;
		}
		else{
			num /= arr[idx];
		}
	}
	
	return num;
}

void dfs(int cnt, int result){
	if(cnt == n){
		Max = max(Max, result);
		Min = min(Min, result);
		return;
	}
	else{
		for(int i=0;i<4;i++){
			if(oper[i] == 0) continue;
			
			oper[i]--;
			int tmp = operation(result, i, cnt);
			dfs(cnt+1, tmp);
			oper[i]++;
		}
	}
}

int main(){
	cin >> n;
	for(int i=0;i<n;i++) cin >> arr[i];
	for(int i=0;i<4;i++) cin >> oper[i];
	
	dfs(1, arr[0]);
	
	cout << Max << endl;
	cout << Min << endl;
}
