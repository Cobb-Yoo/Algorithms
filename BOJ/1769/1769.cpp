#include <bits/stdc++.h>
using namespace std;

string solve(string str){
	int len = str.size();
	int tmp = 0;
	
	for(int i=0;i<len;i++){
		tmp += str[i] - '0';
	}
	
	return to_string(tmp);
}

int main(){
	string str; cin >> str;
	int answer = 0;
	
	while(str.size() != 1){
		str = solve(str);
		answer++;
	}
	
	cout << answer << endl;
	
	if(str == "3" || str == "6" || str == "9")cout << "YES";
	else cout << "NO";
}
