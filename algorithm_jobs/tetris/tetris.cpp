#include <iostream>
using namespace std;

bool map[21][21];
int r,c,y,x;

void check(int idx){
	for(int t=1;t<=r;t++){
		if(map[t][idx]){
			if(t-4 >= 1) {
				int cnt = 0;
				
				for(int i=t-4;i<t;i++){
					int j;
					for(j=1;j<=c;j++){
						if(idx == j) continue;
						if(!map[i][j]) break;
					}
					if(j > c)  cnt++;
				}
				
				if(cnt > x){
					y = idx;
					x = cnt;
				}
			}
			return;
		}
	}
	
	int cnt=0;
	for(int i=r-3;i<=r;i++){
		int j;
		for(j=1;j<=c;j++){
			if(idx == j) continue;
			if(!map[i][j]) break;
		}
		if(j > c)  cnt++;
	}
				
	if(cnt > x){
		y = idx;
		x = cnt;
	}
	
}

int main(){
	cin >> c >> r;
	
	for(int i=1;i<=r;i++){
		for(int j=1;j<=c;j++){
			cin >> map[i][j];
		}
	}
	
	for(int i=1;i<=c;i++) check(i);
	
	cout << y << " " << x;
};
