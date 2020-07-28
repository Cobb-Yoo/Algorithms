#include <iostream>
#include <cstring>
using namespace std;

int n,k,w;
int delay[1001];
bool graph[1001][1001];
int visited[1001];

int totalTime(int idx){
	int &result = visited[idx];
	if (result!=-1) return result;

    int time = 0;

    for (int i = 1; i <= n; i++)
		if (graph[i][idx])
			time = max(time, totalTime(i));

    return result = time + delay[idx];
}

int main(){
	int t; cin >> t;
	
	while(t--){
		memset(graph,0,sizeof(graph));
		memset(visited,-1,sizeof(visited));
		
		cin >> n >> k;
		
		for(int i=1;i<=n;i++) cin >> delay[i];
		for(int i=0;i<k;i++){
			int a, b;
			cin >> a >> b;
			
			graph[a][b] = 1;
		}
		cin >> w;
		
		cout << totalTime(w) << endl;
	}
}
