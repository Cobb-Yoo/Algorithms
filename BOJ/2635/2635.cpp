#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> v;
int n;

bool cmp(vector<int> a, vector<int> b){
	return a.size() > b.size();
}

void solve(int num){
	vector<int> tmp;
	tmp.push_back(n);
	tmp.push_back(num);
	int idx = 1;
	
	while(1){
		int a = tmp[idx-1]-tmp[idx];
		
		if(a < 0) break;
		
		tmp.push_back(a);
		idx++;
	}
	
	v.push_back(tmp);
}

int main(){
	cin >> n;
	
	for(int i=n/2;i<=n;i++) solve(i);
	
	sort(v.begin(), v.end(), cmp);
	
	int len = v[0].size();
	cout << len << endl;
	for(int i=0;i<len;i++){
		cout << v[0][i] << " ";
	}
	cout << endl;
}
