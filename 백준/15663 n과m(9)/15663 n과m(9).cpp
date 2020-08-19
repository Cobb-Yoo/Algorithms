#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int arr[8];
bool visited[8];
vector<int> answer;
int n,m;

void dfs(int begin, int cnt){
	if(cnt == m){
		for(int i=0;i<m;i++) cout << answer[i] << " ";
		cout << endl;
		return; 
	}
	
	for(int i=begin+1;i<n;i++){
		if(!visited[i]){
			visited[i] = 1;
			answer.push_back(arr[i]);
			dfs(i,cnt+1);
			answer.pop_back();
			visited[i] = 0;
		}
	}
}

int main(){
	cin >> n >> m;
	
	for(int i=0;i<n;i++) cin >> arr[i];
	sort(arr,arr+n);
	
	for(int i=0;i<n;i++) {
		visited[i] = 1;
		answer.push_back(arr[i]);
		dfs(i,1);
		answer.pop_back();
		visited[i] = 0;
	}
}
