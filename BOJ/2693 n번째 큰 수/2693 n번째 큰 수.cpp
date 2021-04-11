#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
	int t; cin >> t;
	vector<int> v(10);
	
	for(int i=0;i<t;i++){
		for(int j=0;j<10;j++) cin >> v[j];
		
		sort(v.begin(), v.end());
		
		cout << v[7] << endl;
	}
}
