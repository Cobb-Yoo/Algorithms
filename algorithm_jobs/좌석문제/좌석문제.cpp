#include <iostream>
using namespace std;

int map[1001][1001];
int option[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
int r,c,t;
int a,b;

void solve(){
	int y=1,x=1, angle=0;
	for(int i=1;i<=r*c;i++){
		map[y][x] = i;
		
		if(map[y][x] == t){
			a = y;
			b = x;
		}
		
		int tmpy = y + option[angle][0];
		int tmpx = x + option[angle][1];
		
		if(map[tmpy][tmpx] || 1>tmpy || c<tmpy || 1>tmpx || r<tmpx){			
			angle = (angle+1)%4;
		}
		
		y += option[angle][0];
		x += option[angle][1];
	}
}

int main(){
	cin >> r >> c >> t;
	
	if(t > r*c) {
		cout << 0;
		return 0;
	}
	
	solve();
	
	cout << b << " " << a;
	
}
