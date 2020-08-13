#include <iostream>
#include <cstring>
#include <queue>
#include <string>
using namespace std;

const int MAX = 10000;
int a,b;
bool visited[MAX];

string bfs(){
	queue<pair<int,string>> q;
	q.push({a,""});
	visited[a] = 1;
	
	while(!q.empty()){
		int n = q.front().first;
		string change = q.front().second;
		q.pop();
		
		if(n == b) return change;
		
		int curNum = (2*n)%MAX;
		if(!visited[curNum]){
			visited[curNum] = 1;
			q.push({curNum, change+'D'});
		}
		
		curNum = n-1 < 0 ? 9999 : n-1;
		
		if(!visited[curNum]){
			visited[curNum] = 1;
			q.push({curNum, change+'S'});
		}
		
		curNum = (n%1000)*10 +n/1000;
		if(!visited[curNum]){
			visited[curNum] = 1;
			q.push({curNum,change+'L'});
		}
		
		curNum = (n%10)*1000+n/10;
		if(!visited[curNum]){
			visited[curNum] = 1;
			q.push({curNum,change+'R'});
		}
	}
}

int main(){
	int t; cin >> t;
	
	for(int T=0;T<t;T++){
		memset(visited,0,sizeof(visited));
		cin >> a >> b;
		
		cout << bfs() << endl;
	}
}
