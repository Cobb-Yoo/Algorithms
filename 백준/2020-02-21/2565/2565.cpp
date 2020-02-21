#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool comp (vector<int> &a, vector<int> &b){
	return a[0] < b[0];
}

int main(){
	int len=0;
	int cnt;
	cin >> cnt;
	int list[cnt];
	int MAX=0;
	
	vector<vector<int>> v(cnt);
	
	for(int i=0;i<cnt;i++){
		v[i] = vector<int> (2);
		
		cin >> v[i][0] >> v[i][1];
	}
	
	sort(v.begin(),v.end(),comp);
	
	for(int i=0;i<cnt;i++){
		int m=0;
		for(int j=0;j<i;j++){
			if(v[i][1] > v[j][1] && m < list[j]) m = list[j];
		}
		
		list[i] = m + 1;
		if(MAX < list[i]) MAX = list[i];
	}
	
	cout << cnt - MAX << endl;
}

