#include <iostream>
#include <cstring>
#include <string>
using namespace std;

bool visited['Z'+1];
char map[20][20];
int option[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
int answer = 0;
int r,c;

void f(int a, int b,int cnt){
	for(int i=0;i<4;i++){
		int y = a + option[i][0];
		int x = b + option[i][1];
		
		if(0<=y&&y<r && 0<=x&&x<c){
			if(!visited[map[y][x]]){
				visited[map[y][x]] = 1;
				f(y,x,cnt+1);
				visited[map[y][x]] = 0;
			}
		}
	}
	
	answer = max(answer, cnt);
}

int main(){
	cin >> r >> c;
	for(int i=0;i<r;i++) cin >> map[i];
	
	visited[map[0][0]] = 1;
	
	f(0,0,1);
	
	cout << answer << endl;
}
