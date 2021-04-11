#include <iostream>
#include <cstring>
using namespace std;

int map[20][20];
int col[4];
int row[4];
int option[4][2] = {{1,0},{-1,0},{0,-1},{0,1}};
int n,m,x,y,k;

void rotation(int oper){
	//col = [bottom, right, top, left];
	//row = [bottom, front, top, back];
	
	int tmp;
	
	switch(oper){
		case 1:
			tmp = col[0];
			for(int i=0;i<3;i++) col[i] = col[i+1];
			col[3] = tmp;
			
			row[0] = col[0];
			row[2] = col[2];
			
			break;
		case 2:
			tmp = col[3];
			for(int i=3;i>0;i--) col[i] = col[(i-1)];
			col[0] = tmp;
			
			row[0] = col[0];
			row[2] = col[2];
			
			break;
			
		case 3:
			tmp = row[0];
			for(int i=0;i<3;i++) row[i] = row[i+1];
			row[3] = tmp;
			
			col[0] = row[0];
			col[2] = row[2];
			
			break;
		case 4:
			tmp = row[3];
			for(int i=3;i>0;i--) row[i] = row[(i-1)];
			row[0] = tmp;
			
			col[0] = row[0];
			col[2] = row[2];
			
			break;
	}
}

void move(int oper){
	rotation(oper);
	
	if(map[y][x] == 0){
		map[y][x] = col[0];
	}
	else{
		col[0] = map[y][x];
		row[0] = map[y][x];
		map[y][x] = 0;
	}
	
	cout << col[2] << endl;
}
 
int main(){
	memset(col, 0, sizeof(col));
	memset(row, 0, sizeof(row));
	 
	cin >> n >> m >> y >> x >> k;
	
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin >> map[i][j];
		}
	}
	
	for(int i=0;i<k;i++) {
		int oper;
		cin >> oper;
		
		int next_x = x + option[oper-1][0];
		int next_y = y + option[oper-1][1];
		
		if(0<=next_x&&next_x<m && 0<=next_y&&next_y<n) {
			x = next_x;
			y = next_y;
			
			move(oper);
		}
	}
	
	return 0;
}
