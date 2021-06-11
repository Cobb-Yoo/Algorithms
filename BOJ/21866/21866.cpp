#include <bits/stdc++.h>
using namespace std;

int main(){
	int score = 0;
	int check = 100;
	for(int tmp,i=0;i<9;i++){
		cin >> tmp;
		
		if(tmp > check){
			cout << "hacker";
			exit(0);
		}
		
		score += tmp;
		
		if(i&1) check += 100;
	}
	
	if(score >= 100) cout << "draw";
	else cout << "none\n";
}
