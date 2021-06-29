#include <bits/stdc++.h>
using namespace std;

const int Max = 1000;
int graph[Max][5];

int main(){
	int n; cin >> n;
	vector<vector<int>> v(n);
	
	for(int i=0;i<n;i++){
		for(int j=0;j<5;j++){
			cin >> graph[i][j];
		}
	}
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			for(int k=0;k<5;k++){
				if(i == j) continue;
				
				if(graph[i][k] == graph[j][k]){
					v[i].push_back(j);
					break;
				}
			}
		}
	}
	
	int m = v[0].size();
	int idx = 1;
	
	for(int i=1;i<n;i++){
		if(m < v[i].size()){
			m = v[i].size();
			idx = i+1;
		}
	}
	
	cout << idx << endl;
}
