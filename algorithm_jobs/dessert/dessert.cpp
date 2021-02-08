#include <iostream>
#include <vector>
using namespace std;

int n,cnt;
char option[] = {'+','-','.'};
int a[200];
char b[200];

void solve(int idx, vector<char> v){
	if(idx == n){
		a[0] = 1;
		int a_idx = 1;
		int b_idx = 0;
		
		for(int i=0;i<n-1;i++){
			if(v[i] == option[2]){
				int tmp;
				if(i+2>=10) tmp = a[a_idx-1] * 100 + i+2;
				else tmp = a[a_idx-1] * 10 + i+2;
				
				a[a_idx-1] = tmp;
			}
			else{
				a[a_idx++] = i+2;
				b[b_idx++] = v[i];
			}
		}
		
		int num = a[0];
		
		for(int i=0;i<b_idx;i++){
			if(b[i] == option[0]) num += a[i+1];
			else num -= a[i+1];
		}
		
		if(num == 0){
			cnt++;
			if(cnt > 20) return;
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
