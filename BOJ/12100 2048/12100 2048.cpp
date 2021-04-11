#include <iostream>
#include <queue>
using namespace std;

int map[20][20];
int n;
int answer = 0;

void shift(int index){
	queue<int> q;
	
	if(index == 0){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(map[i][j]) q.push(map[i][j]);
				map[i][j] = 0;
			}
			
			int idx=0;
			while(!q.empty()){
				int tmp = q.front();
				q.pop();
				
				if(map[i][idx] == 0)		map[i][idx] = tmp;
				else if(map[i][idx] == tmp) map[i][idx++] *= 2;
				else 						map[i][++idx] = tmp;
			}
		}
	}
	else if(index == 1){
		for(int i=0;i<n;i++){
			for(int j=n-1;j>=0;j--){
				if(map[i][j]) q.push(map[i][j]);
				map[i][j] = 0;
			}
			
			int idx=n-1;
			while(!q.empty()){
				int tmp = q.front();
				q.pop();
				
				if(map[i][idx] == 0)		map[i][idx] = tmp;
				else if(map[i][idx] == tmp) map[i][idx--] *= 2;
				else 						map[i][--idx] = tmp;
			}
		}
	}
	else if(index == 2){
		for(int j=0;j<n;j++){
			for(int i=n-1;i>=0;i--){
				if(map[i][j]) q.push(map[i][j]);
				map[i][j] = 0;
			}
			
			int idx=n-1;
			while(!q.empty()){
				int tmp = q.front();
				q.pop();
				
				if(map[idx][j] == 0)		map[idx][j] = tmp;
				else if(map[idx][j] == tmp)	map[idx--][j] *= 2;
				else 						map[--idx][j] = tmp;
			}
		}
	}
	else if(index == 3){
		for(int j=0;j<n;j++){
			for(int i=0;i<n;i++){
				if(map[i][j]) q.push(map[i][j]);
				map[i][j] = 0;
			}
			
			int idx=0;
			while(!q.empty()){
				int tmp = q.front();
				q.pop();
				
				if(map[idx][j] == 0)		map[idx][j] = tmp;
				else if(map[idx][j] == tmp)	map[idx++][j] *= 2;
				else 						map[++idx][j] = tmp;
			}
		}
	}
}

void dfs(int cnt){
	if(cnt == 5){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				answer = max(answer, map[i][j]);
			}
		}
		return;
	}
	
	int originMap[n][n];
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			originMap[i][j] = map[i][j];
		}
	}
	
	for(int t=0;t<4;t++){
		shift(t);
		dfs(cnt+1);
		
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				map[i][j] = originMap[i][j];
			}
		}
	}
}

int main(){
	cin >> n;
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin >> map[i][j];
		}
	}
	
	dfs(0);
	
	cout << answer << endl;
}
