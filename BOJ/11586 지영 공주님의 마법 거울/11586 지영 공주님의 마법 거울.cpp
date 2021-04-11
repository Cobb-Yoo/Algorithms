#include <iostream>
using namespace std;

int main(){
	int n; cin >> n;
	
	char map[n][n];
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin >> map[i][j];
		}
	}
	
	int cur; cin >> cur;
	
	if(cur == 1){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				cout << map[i][j];
			}
			cout << "\n";
		}
	}
	else if(cur == 2){
		for(int i=0;i<n;i++){
			for(int j=n-1;j>=0;j--){
				cout << map[i][j];
			}
			cout << "\n";
		}
	}
	else{
		for(int i=n-1;i>=0;i--){
			for(int j=0;j<n;j++){
				cout << map[i][j];
			}
			cout << "\n";
		}
	}
}
