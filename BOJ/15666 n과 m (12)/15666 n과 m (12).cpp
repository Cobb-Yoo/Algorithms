#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;
int n,m;
int visited[10001];
int len;
int arr[8];

void dfs(int cnt, int idx){
	if(cnt == m){
		for(int i=0;i<m;i++){
			cout << arr[i] << " ";
		}
		cout << endl;
		return;
	}
	
	for(int i=0;i<len;i++){
		if(v[i] < idx) continue;
		
		arr[cnt] = v[i];
		dfs(cnt+1, v[i]);
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n >> m;
	
	int tmp;
	for(int i=0;i<n;i++) {
		cin >> tmp;
		if(!visited[tmp]){
			visited[tmp] = 1;
			v.push_back(tmp);
		}
	}
	
	
	sort(v.begin(), v.end());
	len = v.size();
	
	dfs(0, 0);
}
