#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n; cin >> n;
	map<string, bool> m;
	vector<string> v;
	for(int i=0;i<n;i++){
		string name, move;
		cin >> name >> move;
		
		if(m.count(name)){
			if(move=="enter") m[name] = 1;
			else m[name] = 0;
			continue;
		}
		
		v.push_back(name);
		m[name] = 1;
	}
	
	sort(v.begin(), v.end(), greater<string>());
	
	for(int i=0;i<v.size();i++){
		if(m[v[i]]) cout << v[i] << "\n";
	}
}
