#include <iostream>
using namespace std;

const int MAX = 100;
int map[MAX+1][MAX+1];
int cnt;

int main(){
	for(int x1,y1,x2,y2,i=0;i<4;i++){
		cin >> x1 >> y1 >> x2 >> y2;
		
		for(int i=x1;i<x2;i++){
			for(int j=y1;j<y2;j++){
				map[i][j]++;
			}
		}
	}
	
	for(int i=0;i<MAX;i++){
		for(int j=0;j<MAX;j++){
			if(map[i][j]) cnt++;
		}
	}
	
	cout << cnt << endl;
}
