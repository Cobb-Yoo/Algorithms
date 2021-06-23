#include <bits/stdc++.h>
using namespace std;

int arr[50];
vector<vector<int>> v;
vector<vector<int>> answer;
int n, len;

bool check_reverse(int idx){
	for(int start=0;start<len;start++){
		int i,j;
		
		for(i=0,j=len-1;j>=0;i++,j--){
			int tmp = (v[idx][(start+j)%len]+2)%4;
			if(!tmp) tmp = 4;
			
			if(arr[i] != tmp) break;
		}
		
		if(i==len) return 1;
	}
	return 0;
}

bool check(int idx){
	for(int start=0;start<len;start++){
		int i;
		for(i=0;i<len;i++){
			if(arr[i] != v[idx][(start+i)%len]) break;
		}
		
		if(i==len) return 1;
	}
	return 0;
}

void solve(){
	int cnt=0;
	
	for(int i=0;i<n;i++){
		if(check(i) || check_reverse(i)) {
			answer.push_back(v[i]);
			cnt++;
		}
	}
	
	cout << cnt << endl;
	for(int i=0;i<answer.size();i++){
		for(int j=0;j<len;j++){
			cout << answer[i][j] << " ";
		}
		cout << "\n";
	}
}

int main(){
	cin >> len;
	
	for(int i=0;i<len;i++)
		cin >> arr[i];
		
	cin >> n;
	
	for(int i=0;i<n;i++){
		vector<int> tmp;
		for(int tmp_n,j=0;j<len;j++){
			cin >> tmp_n;
			tmp.push_back(tmp_n);
		}
		v.push_back(tmp);
	}
	
	solve();
}
