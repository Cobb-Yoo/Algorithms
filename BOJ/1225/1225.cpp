#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll answer;

void solve(string a, string b){
	int lenA = a.size();
	int lenB = b.size();
	
	for(int i=0;i<lenA;i++){
		for(int j=0;j<lenB;j++){
			answer += (a[i]-'0')*(b[j]-'0');
		}
	}
}

int main(){
	string a,b;
	
	cin >> a >> b;
	
	solve(a, b);
	
	cout << answer << endl;
}
