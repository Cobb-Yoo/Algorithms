#include <bits/stdc++.h>
using namespace std;
char Map[3][3];

int check(char ch){
	int cnt = 0;
	
	for(int j,i=0;i<3;i++){
		for(j=0;j<3;j++){
			if(Map[i][j] != ch) break;
		}
		
		if(j == 3) cnt++;
		
		for(j=0;j<3;j++){
			if(Map[j][i] != ch) break;
		}
		
		if(j == 3) cnt++;
	}
	
	if(Map[0][0] == ch && Map[0][0] == Map[1][1] && Map[1][1] == Map[2][2]) cnt++;
	if(Map[0][2] == ch && Map[0][2] == Map[1][1] && Map[1][1] == Map[2][0]) cnt++;
	
	return cnt;
}

bool solve(string str){
	int o = 0, x = 0, dot = 0;
	int len = str.size();
	
	int idx=0;
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			Map[i][j] = str[idx++];
			
			if(Map[i][j] == 'O') o++;
			else if(Map[i][j] == 'X') x++;
			else dot++;
		}
	}
		
	int cnt1 = check('X');
	int cnt2 = check('O');
	
	if(cnt1&&cnt2) return 0;
	else if(x==o+1 && cnt1) return 1;
	else if(x==o && cnt2) return 1;
	else if(x==5 && o==4 && !cnt1 && !cnt2) return 1;
	else return 0;
}

int main(){
	string str;
	
	while(cin >> str && str != "end"){
		if(solve(str)) cout << "valid\n";
		else cout << "invalid\n";
	}
}
