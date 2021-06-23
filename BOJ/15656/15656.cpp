#include <bits/stdc++.h>
using namespace std;

const int Max = 10001;
int n,m;
vector<int> v;
int answer[Max];

void solve(int cnt){
	if(cnt == m) {
		for(int i=0;i<m;i++){
			cout << answer[i] << " ";
		}
		cout << "\n";
		return;
	}
	
	for(int i=0;i<n;i++){
		answer[cnt] = v[i];
		solve(cnt+1);
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	
	cin >> n >> m;
	
	for(int tmp,i=0;i<n;i++){
		cin >> tmp; v.push_back(tmp);
	}
	
	sort(v.begin(), v.end());
	
	solve(0);
}
