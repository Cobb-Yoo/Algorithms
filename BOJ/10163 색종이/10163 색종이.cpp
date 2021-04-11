#include <iostream>
#include <cstring>
using namespace std;

int map[101][101];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	memset(map,0,sizeof(map));
	int n; cin >> n;
	
	for(int k=1;k<=n;k++){
		int y,x;
		int w,h;
		
		cin >> x >> y >> w >> h;
		
		for(int i=y;i<y+h;i++){
			for(int j=x;j<x+w;j++){
				map[i][j] = k;
			}
		}
	}
	
	for(int k=1;k<=n;k++){
		int sum = 0;
		
		for(int i=0;i<101;i++){
			for(int j=0;j<101;j++){
				if(map[i][j] == k) sum++;
			}
		}
		
		cout << sum << "\n";
	}
}
