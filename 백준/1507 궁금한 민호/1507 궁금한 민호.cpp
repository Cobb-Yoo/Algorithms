#include <iostream>
#include <cstring>
using namespace std;

int map[20][20];
bool visited[20][20];
int n;
int result=0;

void floyd(){
	for(int k=0;k<n;k++){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(i==j || j==k || k==i) continue;
				else if(map[i][j] > map[i][k] + map[k][j]){
					result=-1;
					return;
				}
				else if(map[i][j] == map[i][k]+map[k][j]){
					visited[i][j] = 0;
				}
			}
		}
	}
}

int main(){
	memset(visited,1,sizeof(visited));
	cin >> n;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin >> map[i][j];
		}
	}
	
	floyd();
	
	if(result==-1) cout << -1 << endl;
	else{
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(visited[i][j]) result+=map[i][j];
			}
		}
		
		cout << result/2 << endl;
	}
	
}
