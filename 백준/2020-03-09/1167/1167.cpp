#include <iostream>
#include <vector>
#include <cstring>
#define m make_pair
using namespace std;

const int MAX = 100000;
vector<pair<int,int>> arr[MAX+1];
bool visited[MAX+1];
int n;

int farthesNode=0;
int diameter=0;

void dfs(int node,int cost){
	if(visited[node]) return;
	visited[node] = 1;
	
	if(diameter < cost){
		diameter = cost;
		farthesNode = node;
	}
	
	for(int i=0;i<arr[node].size();i++){
		dfs(arr[node][i].first, cost+arr[node][i].second);
	}
}

int main(){
	cin >> n;
	
	for(int i=0;i<n;i++){
		int node;
		cin >> node;
		
		while(1){
			int node2,cost;
			cin >> node2;
			
			if(node2 == -1) break;
			
			cin >> cost;
			
			arr[node].push_back(m(node2,cost));
		}
	}
	
	memset(visited,0,sizeof(visited));
	dfs(1,0);
	memset(visited,0,sizeof(visited));
	diameter=0;
	dfs(farthesNode,0);
	
	cout << diameter << endl;
}
