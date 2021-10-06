#include <bits/stdc++.h>
using namespace std;

map<string, bool> m;

int main(){
	int answer = 0;
	int N, M;
	cin >> N >> M;
	
	string tmp;
	for(int i=0;i<N;i++){
		cin >> tmp;
		
		m[tmp] = 1;
	}
	
	for(int i=0;i<M;i++){
		cin >> tmp;
		
		if(m[tmp]) answer++;
	}
	
	cout << answer << endl;
}



