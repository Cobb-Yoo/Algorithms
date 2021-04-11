#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool cmp(vector<int> a, vector<int> b){
	if(a[0] == b[0]){
		if(a[1] == b[1]){
			if(a[2] == b[2]) return a[3] > b[3];
			return a[2] > b[2];
		}
		return a[1] > b[1];
	}
	return a[0] > b[0];
}

int main(){
	int n; cin >> n;
	
	vector<vector<int>> v;
	v.push_back({-1,-1,-1,-1,-1});
	for(int i=1;i<4;i++) v.push_back({0,0,0,0,i});
	
	for(int i=0;i<n;i++){
		for(int j=1;j<=3;j++){
			int num; cin >> num;
			
			v[j][num]++;
			v[j][0] += num;
		}
	}
	
	sort(v.begin(), v.end(), cmp);
	
	if(v[0][0] == v[1][0] && v[0][1] == v[1][1] && v[0][2] == v[1][2] && v[0][3] == v[1][3]) cout << 0 << " " << v[0][0] << endl;
	else cout << v[0][4] << " " << v[0][0] << endl;
	
	
}
