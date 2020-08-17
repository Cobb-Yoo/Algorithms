#include <iostream>
#include <vector>
using namespace std;

vector<int> v[501];
bool visited[501];
int n,m;

void find(int nodeNum){
	for(int i=0;i<v[nodeNum].size();i++){
		int next = v[nodeNum][i];
		visited[next] = 1;
	}
	
	if(nodeNum == 1){
		for(int i=0;i<v[nodeNum].size();i++){
			int next=v[nodeNum][i];
			find(next);
		}
	}
}

int main(){
	cin >> n >> m;
	
	for(int i=0;i<m;i++){
		int a,b;
		cin >> a >> b;
		
		v[a].push_back(b);
		v[b].push_back(a);
	}
	
	find(1);
	
	int answer = 0;
	
	for(int i=2;i<=n;i++){
		if(visited[i]) answer++;
	}
	
	cout << answer << endl;
}
