#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int Max = 50;
vector<int> graph[Max+1];
int map[Max+1][Max+1];
bool fact[Max+1];
bool visited[Max+1];
int n,m;

void factCheck(){
	for(int i=1;i<=Max;i++){
		if(fact[i] && !visited[i]){
			
			visited[i] = 1;
			int len = graph[i].size();
			queue<int> q;
			
			for(int j=0;j<len;j++){
				if(!visited[graph[i][j]]){
					q.push(graph[i][j]);
					visited[graph[i][j]] = 1;
					fact[graph[i][j]] = 1;
				}
			}
				
					
			
			while(!q.empty()){
				int a = q.front();
				q.pop();
				
				len = graph[a].size();
				
				for(int j=0;j<len;j++)
					if(!visited[graph[a][j]]){
						q.push(graph[a][j]);
						visited[graph[a][j]] = 1;
						fact[graph[a][j]] = 1;
					}
						
			}
		}
	}
}

void countAnswer(){
	int answer = 0;
	
	for(int i=0;i<m;i++){
		int j;
		for(j=1;j<=map[i][0];j++){
			if(fact[map[i][j]]) break;
		}
		if(j == map[i][0]+1) answer++;
	}
	
	cout << answer << endl;
}

int main(){
	cin >> n >> m;
	
	int num; cin >> num;
	for(int tmp,i=0;i<num;i++){
		cin >> tmp;
		fact[tmp]=1;
	}
	
	for(int num,i=0;i<m;i++){
		cin >> num;
		
		map[i][0] = num;
		for(int j=1;j<=num;j++) cin >> map[i][j];
		
		for(int j=1;j<=num;j++){
			for(int k=1;k<=num;k++){
				if(j == k) continue;
				graph[map[i][j]].push_back(map[i][k]);
			}
		}
	}
	
	factCheck();
	countAnswer();
}
