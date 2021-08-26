#include <bits/stdc++.h>
using namespace std;

int main(){
	vector<int> v(5);
	
	int avg = 0;
	for(int i=0;i<5;i++){
		cin >> v[i];
		
		avg += v[i];
	}
	
	sort(v.begin(), v.end());
	
	cout << avg / 5 << endl << v[2];
}
