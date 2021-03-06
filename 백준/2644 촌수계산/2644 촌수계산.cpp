#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int n;
int s_node, e_node;
int range;
vector<int> family[100];
int cache[100];

int bfs(){
	queue<int> q;
	q.push(s_node);
	
	while(!q.empty()){
		int currentNode = q.front();
		q.pop();
		
		if(currentNode == e_node) return cache[e_node];
		
		for(int i=0;i<family[currentNode].size();i++){
			int next = family[currentNode][i];
			
			if(cache[next] == 0){
				q.push(next);
				cache[next] = cache[currentNode]+1;
			}
		}
	}
	return -1;
}

int main(){
	memset(cache,0,sizeof(cache));
	cin >> n;	
	
	cin >> s_node >> e_node >> range;
	
	for(int i=0;i<range;i++){
		int parent, child;
		cin >> parent >> child;
		
		family[parent].push_back(child);
		family[child].push_back(parent);
	}
	cout << bfs() << endl;
}
