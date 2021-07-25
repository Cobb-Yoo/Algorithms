#include <bits/stdc++.h>
using namespace std;

int main(){
	int n; cin >> n;
	stack<int> s;
	
	for(int tmp, i=0;i<n;i++){
		cin >> tmp;
		
		while(1){
			if(s.empty() || s.top() > tmp) {
				s.push(tmp);
				break;
			}
			else {
				s.pop();
			}
		}
	}
	
	cout << s.size();
}
