#include <iostream>
#define MAX 9
using namespace std;


int arr[MAX][MAX];
bool hor[MAX][MAX+1];//horizon
bool ver[MAX][MAX+1];//vertical
bool square[MAX][MAX+1];//same square
int count=0;

int square_xy(int a, int b){
	return (a / 3) * 3  + b / 3;
}

void dfs(int cnt){
	if(cnt == 81){
		for(int i=0;i<MAX;i++){
			for(int j=0;j<MAX;j++){
				cout << arr[i][j] << ' ';
			}
			cout << endl;
		}
		exit(0);
	}
	int x = cnt / 9; // horizon
	int y = cnt % 9; // vertical
	
	if(arr[x][y]){
		dfs(cnt+1);
	}
	else{
		for(int i=1;i<MAX+1;i++){
			if(!hor[x][i] && !ver[y][i] && !square[square_xy(x,y)][i]){
				hor[x][i] = ver[y][i] = square[square_xy(x,y)][i] = true;
				arr[x][y] = i;
				dfs(cnt+1);
				arr[x][y] = 0;
				hor[x][i] = ver[y][i] = square[square_xy(x,y)][i] = false;
			}
		}
	}
}

int main(){
	for(int i=0;i<MAX;i++){//input
		for(int j=0;j<MAX;j++){
			cin >> arr[i][j];
			
			if(arr[i][j]){
				hor[i][arr[i][j]] = true;
				ver[j][arr[i][j]] = true;
				square[square_xy(i,j)][arr[i][j]] = true;
			}
		}
	}
	
	dfs(0);
	
}
