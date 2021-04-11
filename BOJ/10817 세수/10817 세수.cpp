#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
	vector<int> arr;
	
	for(int i=0;i<3;i++){
		int n;
		cin >> n;
		arr.push_back(n);
	}
	
	sort(arr.begin(),arr.end());
	
	cout << arr[1];
}
