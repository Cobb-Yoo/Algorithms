#include <iostream>
#include <cstring>
using namespace std;

char map[3100][6200];

void star(int n, int a, int b){
	if(n == 3){
		map[b][a] = '*';
		map[b+1][a-1] = '*';
		map[b+1][a+1] = '*';
		map[b+2][a-2] = '*';
		map[b+2][a-1] = '*';
		map[b+2][a] = '*';
		map[b+2][a+1] = '*';
		map[b+2][a+2] = '*';
		return;
	}
	
	star(n/2,a,b);
	star(n/2,a-(n/2),b+(n/2));
	star(n/2,a+(n/2),b+(n/2));
}

int main(){
	memset(map,' ',sizeof(map));
	
	int n; cin >> n;
	
	star(n,n-1,0);
	
	for(int i=0;i<n;i++){
		for(int j=0;j<2*n-1;j++){
			cout << map[i][j];
		}
		cout << endl;
	}
}
