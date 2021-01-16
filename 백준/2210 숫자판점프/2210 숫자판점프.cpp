#include <iostream>
#include <string>
#include <vector>
using namespace std;

int map[5][5];
int option[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
vector<string> v;

void solve(int y, int x, string str, int cnt){
	str += map[y][x];
	
	if(cnt == 6){
		int len = v.size();
		
		for(int i=0;i<len;i++){
			if(v[i] == str) return;
		}
		v.push_back(str);
		return;
	}
	
	
	
	for(int i=0;i<4;i++){
		int nextY = y + option[i][0];
		int nextX = x + option[i][1];
		
		if(0<=nextY&&nextY<5 && 0<=nextX&&nextX<5){
			solve(nextY,nextX,str,cnt+1);
		}
	}
}

int main(){
	for(int i=0;i<5;i++){
		for(int j=0;j<5;j++){
			cin >> map[i][j];
		}
	}
	
	for(int i=0;i<5;i++){
		for(int j=0;j<5;j++){
			solve(i,j,"",1);
		}
	}
	
	cout << v.size() << endl;
}
