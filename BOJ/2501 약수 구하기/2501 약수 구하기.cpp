#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	int n, k; cin >> n >> k;
	vector<int> arr;
	
	for(int i=1;i<=n;i++){
		if(n%i == 0){
			arr.push_back(i);
		}
	}
	
	if(arr.size() < k) cout << 0 << endl;
	else cout << arr[k-1] << endl;
}
