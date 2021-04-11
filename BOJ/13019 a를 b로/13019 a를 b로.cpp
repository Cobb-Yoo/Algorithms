#include <bits/stdc++.h>
using namespace std;

int arr[26];
int brr[26];

int main(){
	string a,b;
	cin >> a >> b;
	int len = a.size();
	
	for(int i=0;i<len;i++){
		arr[a[i]-'A']++;
		brr[b[i]-'A']++;
	}
	
	for(int i=0;i<26;i++){
		if(arr[i] != brr[i]){
			cout << -1;
			return 0;
		}
	}
	
	int ans=len;
	int idx=len-1;
	for(int i=idx;i>=0;i--){
		if(a[i] == b[idx]){
			ans--;
			idx--;
		}
	}
	
	cout << ans << endl;
}
