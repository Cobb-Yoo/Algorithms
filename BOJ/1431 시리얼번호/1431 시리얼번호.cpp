#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(string a, string b){
	if(a.size() != b.size()){
		return a.size() < b.size();
	}
	else {
		int cnta=0;
		int cntb=0;
		int len = a.size();
		
		for(int i=0;i<len;i++){
			if('1'<=a[i] && a[i]<='9'){
				cnta += a[i]-'0';
			}
			
			if('1'<=b[i] && b[i]<='9'){
				cntb += b[i]-'0';
			}
		}
		
		if(cnta == cntb) return a < b;
		return cnta < cntb;
	}
}

int main(){
	int n; cin >> n;
	
	vector<string> v;
	
	for(int i=0;i<n;i++){
		string tmp; cin >> tmp;
		v.push_back(tmp);
	}
	
	sort(v.begin(), v.end(), cmp);
	
	for(int i=0;i<n;i++){
		cout << v[i] << "\n";
	}
}
