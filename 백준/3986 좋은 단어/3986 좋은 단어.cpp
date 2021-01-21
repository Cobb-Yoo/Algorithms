// 3989 좋은단어 s4
#include <iostream>
#include <string>
#include <stack>
using namespace std;

const int MAX = 100000;
int answer;
bool used[MAX+1];
string str;
int len;

void solve(){
	cin >> str;
	len = str.size();
	
	stack<int> s;
	
	for(int i=0;i<len;i++){
		if(s.empty() || s.top() != str[i] ) s.push(str[i]);
		else s.pop();
	}
	
	if(s.size() == 0) answer++;
}

int main(){
	int t; cin >> t;
	
	while(t--){
		solve();
	}
	
	cout << answer << endl;
}
