#include <iostream>
#include <string>
using namespace std;

int n,m;
string s = "abcdefghij";
bool visited[10];

void solve(int idx, int cnt, string str){
	if(cnt == m){
		cout << str << "\n";
		return;
	}
	
	for(int i=0;i<n;i++){
		if(i == idx || visited[i]) continue;
		visited[i] = 1;
		solve(i, cnt+1, str+s[i]);
		visited[i] = 0;
	}
}

int main(){
	cin >> n >> m;
	
	solve(-1, 0, "");
}
