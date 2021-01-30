#include <iostream>
using namespace std;

int option[3] = {-1, 0, 1};
bool map[101][101];
int n,m;

int main(){
	cin >> n >> m;
	int a,b;
	cin >> a >> b;
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin >> map[i][j];
		}
	}
	
	if(map[a][b]) cout << "game over\n";
	else{
		int cnt=0;
		for(int i=0;i<3;i++){
			for(int j=0;j<3;j++){
				if(map[a+option[i]][b+option[j]] == 1) cnt++;
			}
		}
		cout << cnt;
	}
}
