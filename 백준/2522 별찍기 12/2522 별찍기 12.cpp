#include <iostream>
#include <cstring>
using namespace std;

char map[200][200];

int main(){
	memset(map,' ',sizeof(map));
	int n; cin >> n;
	
	int len = 1;
	
	for(int i=n-1;i>=0;i--){
		for(int j=i;j<len+i;j++){
			map[n-1-i][j] = '*';
		}
		len += 2; 
	}
	
	for(int i=0;i<2*n-1;i++){
		for(int j=0;j<n;j++){
			cout << map[j][i];
		}
		cout << endl;
	}
}
