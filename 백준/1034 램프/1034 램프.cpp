#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int n,m,k;
vector<pair<string,int>> v;

int check_zero(string s){	
	int cnt = 0;
	for(int i=0;i<m;i++){
		if(s[i] == '0') cnt++;
	}
	
	return cnt;
}

int main(){
	cin >> n >> m;
	
	for(int i=0;i<n;i++){
		string tmp;
		cin >> tmp;
		
		for(int j=0;j<=v.size();j++){
			if(j == v.size()) {
				v.push_back({tmp,1});
				break;
			}
			else if(v[j].first == tmp) {
				v[j].second++;
				break;
			}
		}
	}
	
	cin >> k;
	
	int answer=0;
	for(int i=0;i<v.size();i++) {
		int check = check_zero(v[i].first);
		
		if(check <= k && check%2 == k%2) answer = max(answer, v[i].second);
	}
	
	cout << answer << endl;
}
