#include <bits/stdc++.h>
using namespace std;

int main(){
	int n; cin >> n;
	string answer = "";
	vector<string> v;
	
	int len;
	int str_size;
	string tmp;
	
	while(n--){
		cin >> tmp;
		
		if(v.empty()) {
			v.push_back(tmp);
			answer = tmp;
			str_size = answer.size();
			continue;
		}
		
		len = v.size();
		
		for(int i=0;i<len;i++){
			for(int j=0;j<str_size;j++){
				if(v[i][j] != tmp[j]){
					answer[j] = '?';
				}
			}
		}
	}
	
	cout << answer << endl;
}
