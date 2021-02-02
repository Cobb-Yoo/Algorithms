#include <iostream>
#include <vector>
using namespace std;

int n,cnt;
char option[] = {'+','-','.'};

void solve(int idx, vector<char> v){
	if(idx == n){
		vector<int> a;
		vector<char> b;
		a.push_back(1);
		
		for(int i=0;i<n-1;i++){
			if(v[i] == option[2]){
				int tmp = a.back() * 10 + i+2;
				a.pop_back();
				a.push_back(tmp);
			}
			else{
				a.push_back(i+2);
				b.push_back(v[i]);
			}
		}
		
		int len = b.size();
		int sum = a[0];
		
		for(int i=0;i<len;i++){
			if(b[i] == option[0]) sum += a[i+1];
			else sum -= a[i+1];
		}
		
		if(sum == 0){
			if(cnt > 21) return;
			cnt++;
			cout << 1 << " ";
			for(int i=0;i<n-1;i++){
				cout << v[i] << " " << i+2 << " ";
			}
			cout << endl;
		}
		return;
	}
	
	for(int i=0;i<3;i++){
		v.push_back(option[i]);
		solve(idx+1, v);
		v.pop_back();
	}
}

int main(){
	cin >> n;
	
	vector<char> v;
	
	solve(1, v);
	
	cout << cnt;
}
