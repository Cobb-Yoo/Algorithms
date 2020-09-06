#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;

int n,m;
map<int,int> numCnt;
vector<int> v;
int answer[8];

void bfs(int idx, int cnt){
	if(cnt == m){
		for(int i=0;i<m;i++) cout << answer[i] << " ";
		cout << endl;
		return;
	}
	
	for(int i=0;i<v.size();i++){
		if(numCnt[v[i]]){
			numCnt[v[i]]--;
			
			if(idx == 0 || answer[idx-1] <= v[i]){
				answer[idx] = v[i];	
				bfs(idx+1, cnt+1);
			}
			numCnt[v[i]]++;
		}
	}
}

int main(){
	cin >> n >> m;
	
	for(int i=0;i<n;i++){
		int num;
		cin >> num;
		
		if(!numCnt.count(num)){
			numCnt[num] = 1;
			v.push_back(num);
		}
		else numCnt[num]++;
	}
	
	sort(v.begin(), v.end());
	
	bfs(0,0);
}
