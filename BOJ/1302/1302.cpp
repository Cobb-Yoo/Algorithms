#include <bits/stdc++.h>
using namespace std;

int n;

int main(){
	cin >> n;
	
	vector<string> arr(n);
	for(int i=0;i<n;i++) cin >> arr[i];
	
	sort(arr.begin(), arr.end());
	
	string tmp = arr[0];
	int Max = 0, num = 0;
	string ans;
	
	for(int i=0;i<n;i++){
		if(tmp == arr[i]){
			num++;
		}
		else {
			if(Max < num){
				Max = num;
				ans = tmp;
			}
			tmp = arr[i];
			num = 1;
		}
	}
	
	if(Max < num) ans = tmp;
	
	cout << ans;
}
