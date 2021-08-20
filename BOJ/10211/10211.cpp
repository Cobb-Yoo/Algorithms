#include <bits/stdc++.h>
using namespace std;

int n;

int main(){
	int t; cin >> t;
	
	while(t--){
		cin >> n;
		
		int answer = -1e9;
		int sum = 0;
		for(int tmp, i=0;i<n;i++){
			cin >> tmp;
			
			sum = max(0, sum) + tmp;
			answer = max(answer, sum);
		}
		
		cout << answer << endl;
	}
}
