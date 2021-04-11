#include <bits/stdc++.h>
using namespace std;

int main(){
	int t; cin >> t;
	
	while(t--){
		int n; cin >> n;
		
		string a,b;
		cin >> a >> b;
		
		int wbCnt=0, bwCnt=0;
		for(int i=0;i<n;i++){
			if(a[i] == 'W' && b[i] == 'B') wbCnt++;
			else if(a[i] == 'B' && b[i] == 'W') bwCnt++;
		}
		
		wbCnt < bwCnt ? cout << bwCnt : cout << wbCnt;
		cout << endl;
	}
}
