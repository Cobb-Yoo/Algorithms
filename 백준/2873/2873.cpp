#include <bits/stdc++.h>
using namespace std;

const int Max = 1000;
int option[4][2] = {{-1,0},{0,-1},{0,1},{1,0}};
int n,m;
int map[Max+1][Max+1];
int Min = 987654321;
int y,x;

int main(){
	cin >> n >> m;
	
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin >> map[i][j];
			
			if((i!=n-1 && j!=m-1) || (i!=n-2 && j!=m-2)){
				Min = min(Min, map[i][j]);
				y = i;
				x = j;
			}	
		}
	}
	
	if((n&1) == 0 && (m&1) ==0){
		
	}
	else if(n&1){
		
	}
	else{
		
	}
}

















