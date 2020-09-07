#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int MAX = 500;

int n;
int indegree[MAX+1];
int duration[MAX+1];
int result[MAX+1];
vector<int> graph[MAX+1];

int main(){
	cin >> n;
	
	for(int i=1;i<=n;i++){
		int time; cin >> time;
		
		duration[i] = time;
		
		int node;
		while(cin >> node && node != -1){
			indegree[i]++;
			graph[node].push_back(i);
		}
	}
	
	queue<int> q;
	
	for(int i=1;i<=n;i++){
		if(!indegree[i]) q.push(i);
	}
	
	while(!q.empty()){
		int node = q.front();
		q.pop();
		
		for(int i=0;i<graph[node].size();i++){
			int nextNode = graph[node][i];
			
			result[nextNode] = max(result[nextNode], result[node]+duration[node]);
			
			if(--indegree[nextNode] == 0) q.push(nextNode);
		}
	}
	
	for(int i=1;i<=n;i++) cout << result[i] + duration[i] << "\n";
}
