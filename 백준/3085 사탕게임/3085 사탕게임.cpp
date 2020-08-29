#include <iostream>
using namespace std;

int n;
char map[50][50];
int answer = 0;
int option[2][2] = {{1,0},{0,1}};

void check(int y, int x){
	int tmp = 1;
	for(int i=0;i<n;i++){
		if(map[y][i] == map[y][i+1]) tmp++;
		else{
			answer = max(answer, tmp);
			tmp = 1;
		}
	}
	answer = max(answer, tmp);
	tmp = 1;
	
	for(int i=0;i<n;i++){
		if(map[i][x] == map[i+1][x]) tmp++;
		else{
			answer = max(answer, tmp);
			tmp = 1;
		}
	}
	answer = max(answer, tmp);
}


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin >> map[i][j];
		}
	}
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			check(i,j);
			
			for(int k=0;k<2;k++){
				int y = i + option[k][0];
				int x = j + option[k][1];
				
				if(0<=y&&y<n && 0<=x&&x<n){
					if(map[i][j] != map[y][x]){
						swap(map[i][j], map[y][x]);
						check(i,j);
						check(y,x);
						swap(map[i][j], map[y][x]);
					}
				}
			}
		}
	}
	
	cout << answer << endl;
}
