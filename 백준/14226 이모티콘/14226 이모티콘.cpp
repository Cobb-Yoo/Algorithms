#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm> 
using namespace std;

const int MAX = 2000;

int n;
bool visited[MAX+1][MAX+1];

int bfs(){
	memset(visited,0,sizeof(visited));
	
	queue<pair<pair<int,int>, int>> q; // val, clip, time;
	q.push({{1,0},0});
	visited[1][0] = 1;
	
	while(!q.empty()){
		int val = q.front().first.first;
		int clip = q.front().first.second;
		int time = q.front().second;
		q.pop();
		
		if(val == n) return time;
		
		if(0 < val && val < MAX){
			if(!visited[val][val]){
				visited[val][val] = 1;
				q.push({{val, val}, time+1});
			}
			
			if(!visited[val-1][clip]){
				visited[val-1][clip] = 1;
				q.push({{val-1,clip},time+1});
			}
		}
		
		if(clip > 0 && val+clip < MAX){
			if(!visited[val+clip][clip]){
				visited[val+clip][clip] = 1;
				q.push({{val+clip,clip},time+1});
			}
		}
	}
}


int main(){
	cin >> n;
	
	cout << bfs() << endl;
}
