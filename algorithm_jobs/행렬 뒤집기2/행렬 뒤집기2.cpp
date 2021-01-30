#include <iostream>
using namespace std;

bool map[11][11];

void toggle(int t){
	map[t][t] = !map[t][t];
	
	for(int i=1;i<11;i++){
		map[i][t] = !map[i][t];
		map[t][i] = !map[t][i];
	}
}

int main(){
	int n; cin >> n;
	
	for(int i=1;i<=10;i++){
		for(int j=1;j<=10;j++){
			cin >> map[i][j];
		}
	}
	
	for(int i=1;i<=n;i++) toggle(i);
	
	for(int i=1;i<11;i++){
		for(int j=1;j<11;j++){
			cout << map[i][j] << " ";
		}
		cout << endl;
	}
}
