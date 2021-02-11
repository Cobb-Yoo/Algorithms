#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int solve(string s){
	int len = s.size();
	
	int left = 0;
	int right = len-1;
	
	while(left < right){
		if(s[left] == s[right]){
			left++;
			right--;
		}
		else{
			int env = 1;
			
			if(s[left+1] == s[right]){
				int tmp_l = left+1;
				int tmp_r = right;
				
				while(tmp_l<tmp_r){
					if(s[tmp_l] != s[tmp_r]) {
						env = 2;
						break;
					}
					else {
						tmp_l++;
						tmp_r--;
					}
				}
			}
			
			if(env != 1 && s[left] == s[right-1]){
				int tmp_l = left;
				int tmp_r = right-1;
				
				env = 1;
				
				while(tmp_l<tmp_r){
					if(s[tmp_l] != s[tmp_r]) {
						env = 2;
						break;
					}
					else {
						tmp_l++;
						tmp_r--;
					}
				}
			}
			
			return env;
		}
	}
	
	return 0;
}

int main(){
	int n; cin >> n;
	
	while(n--){
		string str; cin >> str;
		
		cout << solve(str) << endl;
	}
}
