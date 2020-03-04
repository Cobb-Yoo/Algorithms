#include <iostream>
#include <queue>
using namespace std;

const int MAX = 100000;

int n,m;
int visited[MAX + 1] = {0};
queue<int> q;

int bfs(){
	q.push(n);
	visited[n]=0;
	while(!q.empty()){
		int p = q.front();
		q.pop();
		
		if(p==m) return visited[p];
		
		if(p-1>=0 && visited[p-1] == 0){
			visited[p-1] = visited[p]+1;
			q.push(p-1);
		}
		if(p+1<=MAX && visited[p+1] == 0){
			visited[p+1] = visited[p]+1;
			q.push(p+1);
		}
		if(p*2<=MAX && visited[p*2] == 0){
			visited[p*2] = visited[p]+1;
			q.push(p*2);
		}
	}
}

int main(){
	cin >> n >> m;
	cout << bfs() << endl;
}
