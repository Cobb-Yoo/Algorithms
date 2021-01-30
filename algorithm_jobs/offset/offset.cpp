#include <iostream>
using namespace std;

int map[5][5];
int option[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};

int main(){
	for(int i=0;i<5;i++){
		for(int j=0;j<5;j++){
			cin >> map[i][j];
		}
	}
	
	for(int i=0;i<5;i++){
		for(int k,j=0;j<5;j++){
			for(k=0;k<4;k++){
				int nextY = i + option[k][0];
				int nextX = j + option[k][1];
				
				if(0<=nextY&&nextY<5 && 0<=nextX&&nextX<5)
					if(map[i][j] >= map[nextY][nextX]) break;
			}
			
			if(k == 4) cout << "* ";
			else cout << map[i][j] << " ";
		}
		
		cout << endl;
	}
}
