#include <iostream>
#include <algorithm>
using namespace std;

#define INF 987654321

int graph[100][100];
int n,m;
int startNode, endNode, cost;

void floyd_warshall(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				if(graph[j][i] != INF && graph[i][k] != INF){
					graph[j][k] = min(graph[j][k], graph[j][i]+graph[i][k]);
				}
			}
		}
	}
}

int main(){
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			graph[i][j] = INF;
		}
	}
	
	for(int i=1;i<=m;i++){
		cin >> startNode >> endNode >> cost;
		if(graph[startNode][endNode] > cost){
			graph[startNode][endNode] = cost;
		}
	}
	
	floyd_warshall();
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j || graph[i][j] == INF) cout << 0 << " ";
			else cout << graph[i][j] << " ";
		}
		cout << endl;
	}
}
