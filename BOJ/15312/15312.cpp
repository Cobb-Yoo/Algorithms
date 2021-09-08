#include <bits/stdc++.h>
using namespace std;

int alpha[26] = {3, 2, 1, 2, 3, 3, 2, 3, 3, 2, 2, 1, 2, 2, 1, 2, 2, 2, 1, 2, 1, 1, 1, 2, 2, 1};
vector<int> v;
string a,b;

void solve(){
	int len = a.size();
	
	for(int i=0;i<len;i++){
		v.push_back(alpha[a[i]-'A']);
		v.push_back(alpha[b[i]-'A']);
	}
	
	while(1){
		vector<int> w;
		len = v.size()-1;
		
		for(int i=0;i<len;i++){
			w.push_back((v[i]+v[i+1])%10);
		}
		
		if(w.size() == 2) {
			cout << w[0] << w[1];
			break;
		}
		v = w;
	}
}

int main(){
	cin >> a >> b;
	
	solve();
}
