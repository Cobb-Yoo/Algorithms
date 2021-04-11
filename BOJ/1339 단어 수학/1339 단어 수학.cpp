#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> v;
int alpha[26];
int answer;

void solve(){
	int len = v.size();
	for(int i=0;i<len;i++){
		int num = 1;
		for(int j=v[i].size()-1;j>=0;j--){
			int tmp = v[i][j] - 'A';
			alpha[tmp] += num;
			num*=10;
		}
	}
	
	sort(alpha, alpha+26);
	int idx = 9;
	for(int i=25;i>=0;i--){
		if(alpha[i] > 0){
			answer += idx*alpha[i];
			idx--;
		}
		else break;
	}
}

int main(){
	int n; cin >> n;
	string tmp;
	for(int i=0;i<n;i++){
		cin >> tmp;
		v.push_back(tmp);
	}
	
	solve();
	
	cout << answer;
}
