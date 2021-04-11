#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n,k;

bool cmp(vector<int> a, vector<int> b){
	if(a[1] == b[1]){
		if(a[2] == b[2]){
			if(a[3] == b[3]){
				return a[0] == k;
			}
			return a[3] > b[3];
		}
		return a[2] > b[2];
	}
	return a[1] > b[1];
}

int main(){
	cin >> n >> k;
	
	vector<vector<int>> v;
	
	for(int i=0;i<n;i++){
		int number,gold,silver,bronze;
		cin >> number >> gold >> silver >> bronze;
		
		v.push_back({number,gold,silver,bronze});
	}
	
	sort(v.begin(),v.end(), cmp);
	
	for(int i=0;i<n;i++){
		if(v[i][0] == k){
			cout << i+1 << endl;
		}
	}
}
