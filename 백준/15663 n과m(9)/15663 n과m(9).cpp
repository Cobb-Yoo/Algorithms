#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int MAX = 10001;

vector<int> arr[MAX];
vector<int> haking;
int visited[MAX];
int n,m;
int answer = 0;

void dfs(int idx){
	haking[idx]++;
	answer = max(answer, haking[idx]);
	
	for(int i=0;i<arr[idx].size();i++){
		int next = arr[idx][i];
		if(!visited[next]){
			visited[next] = 1;
			dfs(next);
		}
	}
}

int main(){
	cin >> n >> m;
	
	for(int i=0;i<m;i++){
		int a, b;
		cin >> a >> b;
		
		arr[a].push_back(b);
	}
	haking.resize(n+1,0);
	
	for(int i=1;i<=n;i++){
		memset(visited,0,sizeof(visited));
		
		visited[i]++;
		dfs(i);
	}
	
	for(int i=1;i<=n;i++){
		if(haking[i] == answer){
			cout << i << " ";
		}
	}
}
