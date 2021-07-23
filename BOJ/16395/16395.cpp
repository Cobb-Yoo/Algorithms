#include <bits/stdc++.h>
using namespace std;

const int Max = 31;
int Map[Max][Max];

void init(){
	Map[1][1] = 1;
	
	for(int i=2;i<Max;i++){
		for(int j=1;j<=i;j++){
			if(j==1 && j==i) Map[i][j] = 1;
			else Map[i][j] = Map[i-1][j-1] + Map[i-1][j];
		}
	}
}

int main(){
	init();
	int n,k;
	cin >> n >> k;
	
	cout << Map[n][k] << endl;
}
