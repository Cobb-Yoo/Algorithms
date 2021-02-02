#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	vector<int> v;
	int n,k;
	cin >> n >> k;
	
	for(int tmp,i=0;i<n;i++){
		cin >> tmp;
		v.push_back(tmp);
	}
	
	sort(v.begin(), v.end());
	
	cout << v[v.size()-k];
}
