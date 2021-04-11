#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	int n,m;
	cin >> n >> m;
	
	vector<string> v(n);
	vector<string> s;
	
	for(int i=0;i<n;i++) cin >> v[i];
	
	sort(v.begin(),v.end());
	
	string tmp;
	for(int i=0;i<m;i++) {
		cin >> tmp;
		
		if(binary_search(v.begin(),v.end(), tmp)) s.push_back(tmp);
	}
	
	sort(s.begin(),s.end());
	
	int len = s.size();
	cout << len << endl;
	
	for(int i=0;i<len;i++) cout << s[i] << endl;
}
