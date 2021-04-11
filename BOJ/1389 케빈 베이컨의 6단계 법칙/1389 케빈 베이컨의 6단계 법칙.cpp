#include <iostream>
#include <cstring>
#define inf 987654321
using namespace std;

int n,m;
int map[101][101];
int arr[101];

void setMap(int a, int b, int num){
	map[a][b] = num;
	map[b][a] = num;
}

void floydWarshall(){
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(map[i][k] + map[k][j] < map[i][j]){
					map[i][j] = map[i][k] + map[k][j];
				}
			}
		}
	}
}

int main(){
	cin >> n >> m;
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			map[i][j] = inf;
		}
	}
	
	for(int i=1;i<=n;i++) map[i][i] = 0;
	
	for(int i=0;i<m;i++){
		int a,b;
		cin >> a >> b;
		
		setMap(a,b,1);
	}
	
	floydWarshall();
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			arr[i] += map[i][j];
		}
	}
	
	int MIN=arr[1];
	int idx = 1;
	
	for(int i=2;i<=n;i++){
		if(MIN > arr[i]){
			MIN = arr[i];
			idx = i;
		}
	}
		
	cout << idx << endl;
}
