#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
	int n; cin >> n;
	vector<int> data(n);
	
	for(int i=0;i<n;i++) cin >> data[i];
	
	if(prev_permutation(data.begin(), data.end())){
		for(int i=0;i<n;i++) cout << data[i] << " ";
	}
	else {
		cout << -1;
	}
}
