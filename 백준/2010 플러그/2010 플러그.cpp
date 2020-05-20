#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(int a, int b){
	return a > b;
}

int main(){
	vector<int> arr;
	int n;
	cin >> n;
	
	int answer = 0;
	for(int i=0;i<n;i++) {
		int tmp;
		cin >> tmp;
		arr.push_back(tmp);
	}
	
	for(int i=0;i<n;i++){
		answer += arr[i];
	}
	
	cout << answer - n + 1 << endl;
}
