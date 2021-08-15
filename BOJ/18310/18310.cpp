#include <bits/stdc++.h>
using namespace std;

vector<int> v;
int n;

int main(){
	cin >> n;
	
	vector<int> v;
	for(int tmp, i=0;i<n;i++){
		cin >> tmp;
		v.push_back(tmp);
	}
	
	sort(v.begin(), v.end());
	
	cout << v[(n-1)/2];
}
