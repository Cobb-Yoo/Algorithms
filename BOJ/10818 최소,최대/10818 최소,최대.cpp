#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
	int n;
	cin >> n;
	vector<int> arr;
	
	for(int i=0;i<n;i++){
		int tmp;
		cin >> tmp;
		arr.push_back(tmp);
	}
	
	sort(arr.begin(),arr.end());
	
	cout << arr[0] << " " << arr[n-1] << endl;
}
