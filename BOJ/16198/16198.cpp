#include <bits/stdc++.h>
#define ll long long
using namespace std;

vector<int> v;
int n;
ll answer;

void solve(ll result){
	int len = v.size();
	
	if(len == 2){
		answer = max(answer, result);
		return;
	}
	
	for(int i=1;i<len-1;i++){
		int tmp = v[i];
		
		result += v[i-1]*v[i+1];
		v.erase(v.begin()+i);
		
		solve(result);
		
		v.insert(v.begin()+i, tmp);
		result -= v[i-1]*v[i+1];
		
	}
}

int main(){
	cin >> n;
	
	v.resize(n);
	
	for(int i=0;i<n;i++){
		cin >> v[i];
	}
	
	solve(0);
	
	cout << answer << endl;
}
