#include <iostream>
#include <cstring>
using namespace std;

int cnt = 0;
bool visited[100001];
bool done[100001];
int arr[100001];

void dfs(int n){
	visited[n] = 1;
	
	int next = arr[n];
	if(!visited[next]) dfs(next);
	
	else if(!done[next]){
		for(int i=next;i!=n;i=arr[i]){
			cnt++;
		}
		cnt++;
	}
	
	done[n]=1;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t; cin >> t;
	
	while(t--){
		memset(visited,0,sizeof(visited));
		memset(done,0,sizeof(done));
		
		int n; cin >> n;
		
		for(int i=1;i<=n;i++) cin >> arr[i];
		
		cnt = 0;
		for(int i=1;i<=n;i++){
			if(!visited[i]) dfs(i);
		}
		
		cout << n-cnt << "\n";
	}
}
