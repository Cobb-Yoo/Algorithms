#include <bits/stdc++.h>
using namespace std;
vector<string> v;

void check(string a, string b){
	cout << "aa : " << a << " and " << b << endl;
	int alen = a.size();
	int blen = b.size();
	
	if(alen != blen) {
		v.push_back(b);
		return;
	}
	
	for(int i=0;i<blen;i++){
		if(a != b) {
			cout << "aa : " << a << " and " << b << endl;
			b += b.at(0);
			b.erase(0, 1);
		}
		else{
			cout << "hello\n";
			return;
		}
	}
	
	v.push_back(b);
}
	
int main(){
	int n; cin >> n;
	
	string str;

	
	while(n--){
		cin >> str;
		
		if(v.size() == 0) {
			v.push_back(str);
			n--;
			cin >> str;
		}
		
		for(int i;i<v.size();i++){
			cout << "dd : " << v[i] << endl;
			check(v[i], str);
		}
	}
	
	cout << v.size() << endl;
//	for(auto i : v){
//		cout << i << endl;
//	}
}
