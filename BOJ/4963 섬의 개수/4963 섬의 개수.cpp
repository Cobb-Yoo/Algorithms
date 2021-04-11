#include <iostream>
#include <cstring>
using namespace std;

bool visited[50][50];
int n,m;
int cnt = 0;
int option[3] = {1,0,-1};

void f(int a, int b){
	visited[a][b] = 0;
	
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			if(i == 1 && j == 1) continue;
			
			int y = a + option[i];
			int x = b + option[j];
		
			if(0<=y&&y<n && 0<=x&&x<m && visited[y][x]) f(y,x);	
		}
	}
}


int main(){
	while(cin >> m >> n && n && m){
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				cin >> visited[i][j];
			}
		}
		cnt = 0;
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(visited[i][j]) {
					cnt++; 
					f(i,j);
				}
			}
		}
		cout << cnt << endl;
	}
}
