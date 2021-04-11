#include <iostream>
#include <vector>
using namespace std;

const int MAX = 100000;

vector<int> tree[MAX+1];
bool visited[MAX+1];
int parent[MAX+1];

void f(int nodeNum){
	visited[nodeNum] = 1;
	
	for(int i=0;i<tree[nodeNum].size();i++){
		int next = tree[nodeNum][i];
		
		if(!visited[next]){
			parent[next] = nodeNum;
			f(next);
		}
	}
}

int main(){
	int n;
	cin >> n;
	
	for(int i=0;i<n-1;i++){
		int a, b;
		cin >> a >> b;
		
		tree[a].push_back(b);
		tree[b].push_back(a);
	}
	
	f(1);
	
	for(int i=2; i<= n;i++){
		cout << parent[i] << endl;
	}
}
