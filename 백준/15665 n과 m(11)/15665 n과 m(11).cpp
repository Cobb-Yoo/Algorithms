#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

map<int,int> numCnt;
int answer[7];
vector<int> v;
int n,m;

void bfs(int idx, int cnt){
	if(cnt == m){
		for(int i=0;i<m;i++) cout << answer[i] << " ";
		cout << "\n";
		return;
	}
	
	for(int i=0;i<v.size();i++){
		answer[idx] = v[i];
		bfs(idx+1, cnt+1);
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	
	for(int i=0;i<n;i++){
		int num;
		cin >> num;
		
		if(!numCnt.count(num)){
			numCnt[num] = 1;
			v.push_back(num);
		}
	}
	
	sort(v.begin(), v.end());
	
	bfs(0, 0);
}
