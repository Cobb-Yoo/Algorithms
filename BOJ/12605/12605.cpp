#include <bits/stdc++.h>
using namespace std;

int main(){
	int n; cin >> n;
	cin.ignore(); // น๖วม clear 
	
	string s, tmp, answer;
	
	for(int i=1;i<=n;i++){
		getline(cin, s);
		stringstream stream;
		stream.str(s);
		vector<string> v;
		
		while(stream >> s) v.push_back(s);
		
		cout << "Case #" << i << ": ";
		for(int j=v.size()-1;j>=0;j--) cout << v[j] << " ";
		cout << endl;
	}
}
