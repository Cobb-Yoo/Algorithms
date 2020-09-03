#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int n,m;
vector<int> graph[10001];
bool visited[10001];
int cnt;

void dfs(int num){
	visited[num] = 1;
	
	for(int i=0;i<graph[num].size();i++){
		int next = graph[num][i];
		
		if(!visited[next]){
			cnt++;
			dfs(next);
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	
	for(int i=0;i<m;i++){
		int a,b;
		cin >> a >> b;
		
		graph[b].push_back(a);
	}
	
	int nodeCnt = 0;
	vector<int> result;
	
	for(int i=1;i<=n;i++){
		memset(visited,0,sizeof(visited));
		cnt = 0;
		
		dfs(i);
		
		if(nodeCnt == cnt) result.push_back(i);
		else if(nodeCnt < cnt){
			nodeCnt = cnt;
			result.clear();
			result.push_back(i);
		}
	}
	
	sort(result.begin(),result.end());
	
	for(int i=0;i<result.size();i++){
		cout << result[i] << " ";
	}
}
