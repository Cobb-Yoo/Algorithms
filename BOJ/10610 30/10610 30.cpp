#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> arr;

bool cmp(int a,int b){
	return a > b;
}

int main(){
	string n;
	cin >> n;
	int sum = 0;
	bool flag = false;
	
	for(int i=0;i<n.size();i++){
		int tmp = n[i] - '0';
		sum += tmp;
		if(tmp == 0) flag = true;
		arr.push_back(tmp);
	}
	
	if(!flag || sum%3 != 0) cout << -1 << endl;
	else{
		sort(arr.begin(), arr.end(), cmp);
		for(int i=0;i<arr.size();i++) cout << arr[i];
	}
}
