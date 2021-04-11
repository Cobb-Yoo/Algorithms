#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int n,m;
vector<int> v;
int visited[8];
map<int,int> numcnt;

void dfs(int idx, int cnt){
	if(cnt == m){
		for(int i=0;i<m;i++){
			cout << v[visited[i]] << " ";
		}
		cout << '\n';
		
		return;
	}
	
	if(idx == n) return;
	
	for(int i=0;i<v.size();i++){
		if(numcnt[v[i]]){
			numcnt[v[i]]--;
			visited[idx] = i;
			dfs(idx+1, cnt+1);
			numcnt[v[i]]++;
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	
	for(int i=0;i<n;i++){
		int num; cin >> num;
		
		if(!numcnt.count(num)){
			numcnt[num] = 1;
			v.push_back(num);
		}
		else numcnt[num]++;
	}
	
	sort(v.begin(), v.end());
	
	dfs(0,0);
}
