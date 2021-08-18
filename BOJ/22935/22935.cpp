#include <bits/stdc++.h>
using namespace std;

void solve(int n){
	bool str[4];
	string answer = "";
	int tmp = n;
	
	tmp %= 28;
	if(tmp == 0) tmp = 28;
	
	if(tmp > 15) tmp = 30 - tmp;
	
	for(int i=0;i<4;i++){
		if(tmp==0){
			str[i] = 0;
			continue;
		}
		
		if(tmp&1) str[i] = 1;
		else str[i] = 0;
		
		tmp /= 2;
	}
	
	for(int i=3;i>=0;i--){
		if(str[i]) answer += "µþ±â";
		else answer += "V";
	}
	
	cout << answer << endl;
	//printf("%s\n", answer);
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t; cin >> t;
	
	for(int i=0;i<t;i++){
		int num; cin >> num;
		
		solve(num);
	}
}
