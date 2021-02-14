#include <bits/stdc++.h>
using namespace std;

int arr[1001];

bool cmp(int a, int b){
	return a > b;
}

int main(){
	int t; cin >> t;
	
	while(t--){
		int j,n;
		cin >> j >> n;
		
		for(int a,b,i=0;i<n;i++){
			cin >> a >> b;
			arr[i] = a*b;
		}
		
		sort(arr, arr+n, cmp);
		
		int cnt=0;
		for(int i=0;i<n;i++){
			if(j<=0) break;
			
			j -= arr[i];
			cnt++;
		}
		
		cout << cnt << endl;
	}
}
