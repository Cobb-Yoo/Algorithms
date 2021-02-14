#include <bits/stdc++.h>
using namespace std;

int arr[(int)1e6+1];

int main(){
	int n; cin >> n;
	
	int m = 0;
	for(int tmp,i=0;i<n;i++){
		cin >> tmp;
		arr[tmp] = arr[tmp-1]+1;
	
		m = max(m, arr[tmp]);
	}
	
	cout << n - m << endl;
}
