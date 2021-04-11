#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 10000+1;
bool arr[MAX];
int n,m;
vector<int> v;
int answer[10];
int len;

void solve(int cnt, int idx){
	if(cnt == m){
		for(int i=0;i<m;i++){
			cout << answer[i] << " ";
		}
		cout << endl;
		return;
	}
	
	for(int i=0;i<len;i++){
		if(cnt == 0){
			answer[cnt] = v[i];
			solve(cnt+1, i);
		}
		else{
			if(v[i] < v[idx]) continue;
			
			answer[cnt] = v[i];
			solve(cnt+1, i);
		}
		
	}
}

int main(){
	cin >> n >> m;
	
	int tmp;
	for(int i=0;i<n;i++){
		cin >> tmp;
		
		if(!arr[tmp]) v.push_back(tmp);
	}
	
	len = v.size();
	sort(v.begin(), v.end());
	solve(0,0);
}
