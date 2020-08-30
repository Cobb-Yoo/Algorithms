#include <iostream>
using namespace std;

int n,m;
char map[10][10];
pair<int,int> red;
pair<int,int> blue;
pair<int,int> hole;


int main(){
	cin >> n >> m;
	
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin >> map[i][j];
			
			if(map[i][j] == 'R') red = {i,j};
			else if(map[i][j] == 'B') blue = {i,j};
			else if(map[i][j] == 'O') hole = {i,j};
		}
	}
	
	//4가지 움직임에 따라서 red와 blue의 좌표만을 확인해서 움직임의 우선순위를 판단한다.
	//우선순위가 먼저인 공이 끝까지 움직인다.
	//그 다음 우선순위의 공이 움직인다.
	//queue로 움직인 후의 값을 저장하여 bfs를 준비한다. 
}
