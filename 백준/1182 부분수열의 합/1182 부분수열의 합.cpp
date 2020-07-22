#include <iostream>
#include <cstring>
using namespace std;

int arr[20];
bool visited[20];
int n,s;
int answer = 0;

void bfs(int begin, int sum){
	sum += arr[begin];
	
	if(sum == s) answer++;
	
	for(int i=begin+1;i<n;i++) bfs(i,sum);
}

int main(){
	memset(visited,0,sizeof(visited));
	
	cin >> n >> s;
	
	for(int i=0;i<n;i++) cin >> arr[i];
	
	for(int i=0;i<n;i++) bfs(i, 0);
	
	cout << answer << endl;
}
