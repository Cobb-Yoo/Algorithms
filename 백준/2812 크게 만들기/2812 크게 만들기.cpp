#include <iostream>
#include <string>
#include <deque>
using namespace std;

int main(){
	int n,k;
	cin >> n >> k;
	
	string s; cin >> s;
	
	deque<char> dq;
	
	for(int i=0;i<n;i++){
		while(k && !dq.empty() && dq.back() < s[i]){
			dq.pop_back();
			k--;
		}
		
		dq.push_back(s[i]);
	}
	
	int len = dq.size()-k;
	for(int i=0;i<len;i++){
		cout << dq[i];
	}
}
