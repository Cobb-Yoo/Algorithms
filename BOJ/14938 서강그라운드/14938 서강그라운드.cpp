#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;

const int MAX = 100;
vector<pair<int,int>> v[MAX+1];
int arr[MAX+1];
int dist[MAX+1];
int n,m,r;

void solve(int num){
	for(int i=1;i<=n;i++) dist[i] = 987654321;
	
	queue<pair<int,int>> q;
	q.push({num, 0});
	dist[num] = 0;
	
	while(!q.empty()){
		int y = q.front().first;
		int length = q.front().second;
		q.pop();
		
		int len = v[y].size();
		
		for(int i=0;i<len;i++){
			int nextY = v[y][i].first;
			int nextLength = length+v[y][i].second;

			if(m >= nextLength && dist[nextY] > nextLength){
				dist[nextY] = nextLength;
				q.push({nextY, nextLength});
			}
		}
	}
}

int main(){
	cin >> n >> m >> r;

	for(int i=1;i<=n;i++) cin >> arr[i];
	
	for(int a,b,c,i=0;i<r;i++){
		cin >> a >> b >> c;
		
		v[a].push_back({b,c});
		v[b].push_back({a,c});
	}
	
	int answer = 0;
	for(int i=1;i<=n;i++){
		solve(i);
		
		int tmp = 0;
		for(int j=1;j<=n;j++){
			if(dist[j] <= m) tmp += arr[j];
		}
		
		answer = max(tmp, answer);
	}
	
	cout << answer << endl;
}
