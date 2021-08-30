#include <bits/stdc++.h>
using namespace std;

const int Max = 30;
int graph[Max+1][Max+1];

void init(){
	
	
	for(int i=1;i<=Max;i++){
		for(int j=1;j<=Max;j++){
			if(j==1 || j==i){
				graph[i][j] = 1;
			}
			else{
				graph[i][j] = graph[i-1][j-1] + graph[i-1][j];
			}
		}
	}
}

void solve(){
	int answer = 0;
	int r,c,w;
	cin >> r >> c >> w;
	
	for(int i=r;i<r+w;i++){
		for(int j=c;j<c+i-r+1;j++){
			answer += graph[i][j];
//			cout << graph[i][j] << " ";
		}
	}
	
	cout << answer << endl;
}

int main(){
	init();
	
	solve();
}
