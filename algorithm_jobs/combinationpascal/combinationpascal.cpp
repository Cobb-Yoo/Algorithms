#include <iostream>
#define ll long long
using namespace std;

ll arr[31][31];

void init(){
	for(int i=0;i<31;i++){
		for(int j=0;j<=i;j++){
			if(j==0) arr[i][j] = 1;
			else arr[i][j] = arr[i-1][j] + arr[i-1][j-1];
		}
	}
}

int main(){
	init();
	
	int a,b;
	cin >> a >> b;
	
	cout << arr[a][b];
}
