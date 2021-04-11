#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n,m;
bool visited[8];
int arr[8];
vector<int> v;

void dfs(int cnt){
	if(cnt == m){
		for(int i=0;i<cnt;i++) cout << arr[i] << " ";
		cout << "\n";
		return;
	}
	
	for(int i=0;i<n;i++){
		if(!visited[i]){
			visited[i] = 1;
			arr[cnt] = v[i];
			dfs(cnt+1);
			visited[i] = 0;
		}
	}
}

int main(){
	cin >> n >> m;
	
	
	for(int i=0;i<n;i++) {
		int tmp;
		cin >> tmp;
		v.push_back(tmp);
	}
	
	sort(v.begin(), v.end());
	
	dfs(0);
}
