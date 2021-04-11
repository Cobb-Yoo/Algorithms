#include <iostream>
#include <string>
#include <vector>
#include <cstring>
using namespace std;

bool arr[1003002];
vector<int> v;

int answer;

void init(){
	memset(arr,1,sizeof(arr));
	
	for(int i=2;i<=1003001;i++){
		if(arr[i]){
			v.push_back(i);
			
			for(int j=i+i;j<=1003001;j+=i){
				arr[j] = 0;
			}
		}
	}
}
int main(){
	init();
	
	int n; cin >> n;
	
	for(int i=0;i<v.size();i++){
		if(n <= v[i]){
			string s = to_string(v[i]);
	
			bool flag = 1;
			for(int i=0;i<s.size()/2;i++){
				if(s[i] != s[s.size()-1-i]){
					flag = 0;
					break;
				}
			}
			
			if(flag) {
				cout << v[i];
				return 0;
			}
		}
	}
}
