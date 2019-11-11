#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

bool cmp(pair<int, string> a, pair<int, string> b){
	return a.first < b.first;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
	int n;
	cin >> n;
	vector<pair<int, string>> t(n);	
	
	for(int i=0;i<n;i++){
		cin >> t[i].first >> t[i].second;
	}
	
	stable_sort(t.begin(),t.end(),cmp);
	
	for(int i=0;i<n;i++){
		cout << t[i].first << ' ' << t[i].second << '\n';
	}
}
