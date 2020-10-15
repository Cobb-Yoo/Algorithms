#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool cmp(string a, string b){
	if(a < b && a[0] == b[0]) {
		if(a.size() == b.size()) return a < b;
		else return a.size() < b.size();
	}
	return a < b;
}

int main(){
	int t; cin >> t;
	
	while(t--){
		int n; cin >> n;
		vector<string> arr(n);
		
		for(int i=0;i<n;i++) cin >> arr[i];
		
		sort(arr.begin(), arr.end(), cmp);
		
		bool flag = 1;
		
		for(int i=0;i<n-1;i++){
			for(int j=i+1;j<n;j++){
				if(arr[i][0] != arr[j][0]) break;
				
				int len = arr[i].size();
				
				int k;
				for(k=0;k<len;k++){
					if(arr[i][k] != arr[j][k]) break;
				}
				
				if(k == len){
					flag = 0;
					break;
				}
			}
			
			if(!flag) break;
		}
		
		if(flag) cout << "YES\n";
		else cout << "NO\n";
	}
}
