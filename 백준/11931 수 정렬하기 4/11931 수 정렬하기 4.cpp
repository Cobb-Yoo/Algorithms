#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool cmp(int a, int b){
	return a > b;
}

int main(){
	int n; cin >> n;
	vector<int> v;
	
	for(int i=0;i<n;i++){
		int tmp; cin >> tmp;
		v.push_back(tmp);
	}
	
	sort(v.begin(), v.end(), cmp);
	
	for(int i=0;i<n;i++){
		cout << v[i] << "\n";
	}
}
