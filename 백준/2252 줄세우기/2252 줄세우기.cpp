#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main(){
	int n,m;
	cin >> n >> m;
	
	int arr[n+1] = {0,};
	vector<int> v[n+1];
	
	for(int i=0;i<m;i++){
		int a,b;
		cin >> a >> b;
		
		arr[b]++;
		v[a].push_back(b);
	}
	
	queue<int> q;
	for(int i=1;i<=n;i++){
		if(!arr[i]) q.push(i);
	}
	
	while(!q.empty()){
		int tmp = q.front();
		q.pop();
		
		cout << tmp << " ";
		
		for(int i=0;i<v[tmp].size();i++){
			arr[v[tmp][i]]--;
			if(!arr[v[tmp][i]]) q.push(v[tmp][i]);
		}
	}
}
