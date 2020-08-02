#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAX = 20000;

int v,e;
int nodecolor[MAX+1];
vector<int> map[MAX+1];

void dfs(int node, int color){
	nodecolor[node] = color;
	
	for(int i=0;i<map[node].size();i++){
		int next = map[node][i];
		if(!nodecolor[next]) dfs(next,3-color);
	}
}

bool isBipartiteGraph(){
	for(int i=1;i<=v;i++){
		for(int j=0;j<map[i].size();j++){
			int next = map[i][j];
			if(nodecolor[i] == nodecolor[next]) return 0;
		}
	}
	return 1;
}

int main(){
	int t; cin >> t;
	
	while(t--){
		cin >> v >> e;
		memset(nodecolor, 0, sizeof(nodecolor));
		for(int i=0;i<=MAX;i++) map[i].clear();
		//v == 노드의 수
		//e == 간선의 수  
		for(int i=0;i<e;i++){
			int node1, node2;
			cin >> node1 >> node2;
			
			map[node1].push_back(node2);
			map[node2].push_back(node1);
		}
		
		for(int i=1;i<=v;i++){
			if(!nodecolor[i]) dfs(i,1);
		}
		
		if(isBipartiteGraph()) cout << "YES\n";
		else cout << "NO\n";
	}
}
