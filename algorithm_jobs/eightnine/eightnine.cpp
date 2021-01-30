#include <iostream>
using namespace std;

int map[100][100];
int n,m;

int main(){
	cin >> n >> m;
	
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin >> map[i][j];
		}
	}
	
	for(int i=0;i<n;i++){
		for(int j=m-1;j>=0;j--){
			cout << map[i][j] << " ";
		}
		cout << endl;
	}
}
