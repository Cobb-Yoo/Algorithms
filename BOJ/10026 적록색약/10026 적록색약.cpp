#include <iostream>
#include <string>
#include <cstring>
using namespace std;

const int MAX = 100;

char arr[MAX][MAX];
bool visited[MAX][MAX];
int n;

int option[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};

void bfs(int a, int b){
	visited[a][b] = 1;
	
	for(int i=0;i<4;i++){
		int y = a + option[i][0];
		int x = b + option[i][1];
		
		if(0<=x && x<n && 0<=y&&y<n && !visited[y][x]){
			if(arr[a][b] == arr[y][x]) {
				bfs(y,x);
			}
		}
	}
}

int main(){
	memset(visited,0,sizeof(visited));
	cin >> n;
	
	for(int i=0;i<n;i++) cin >> arr[i];
	
	int answer = 0;
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(!visited[i][j]){
				bfs(i,j);
				answer++;
			}
		}
	}
	
	cout << answer << " ";
	
	memset(visited,0,sizeof(visited));
	answer = 0;
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(arr[i][j] == 'R') arr[i][j] = 'G';
		}
	}
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(!visited[i][j]){
				bfs(i,j);
				answer++;
			}
		}
	}
	
	cout <<  answer << endl;
}
