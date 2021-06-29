#include <bits/stdc++.h>
using namespace std;

string checkArr[] = {"000000","001111","010011","0111000","100110","101001","110101","111010"};

string data;
string answer;

void check(string str, int num){
	int idx=0;
	
	for(int i=0;i<8;i++){
		int cnt = 0;
		for(int j=0;j<6;j++){
			if(checkArr[i][j] != str[j]) cnt++;
		}
		
		if(cnt == 1 || cnt == 0) {
			answer += 'A'+i;
			return;
		}
	}
	
	cout << num << endl;
	exit(0);
}

int main(){
	int n; cin >> n;
	cin >> data;
	
	int len = data.size();
	
	for(int i=0;i<len;i+=6){
		string tmp = "";
		
		for(int j=i;j<i+6;j++){
			tmp += data[j];
		}
		
		check(tmp, i/6+1);
	}
	
	cout << answer << endl;
}
