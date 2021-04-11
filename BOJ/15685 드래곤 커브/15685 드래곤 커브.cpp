#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

vector<int> v;
bool map[101][101];
int option[4][2] = {{0,1},{-1,0},{0,-1},{1,0}};

int main(){
	memset(map,0,sizeof(map));
	int n; cin >> n;
	
	for(int i=0;i<n;i++){
		v.clear();
		int y, x, d, g;
		cin >> x >> y >> d >> g;
		
		map[y][x] = 1;		
		v.push_back(d);
		
		for(int j=1;j<=g;j++){
			int len = v.size();
			for(int k=len-1;k>=0;k--){
				v.push_back((v[k]+1)%4);
			}
		}
		
		int len = v.size();
		for(int j=0;j<len;j++){
			y += option[v[j]][0];
			x += option[v[j]][1];
			map[y][x] = 1;
		}
	}
	
	int answer = 0;
	for(int i=0;i<100;i++){
		for(int j=0;j<100;j++){
			if(map[i][j] && map[i+1][j] && map[i][j+1] && map[i+1][j+1]){
				answer++;
			}
		}
	}
	
	cout << answer << endl;
}
