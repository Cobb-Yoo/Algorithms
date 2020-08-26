#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

bool visited[21][21];
int map[21][21];
int arr[5];
int n;
int answer = 987654321;

void count_area(int x, int y, int d1, int d2){
	memset(visited,0,sizeof(visited));
	memset(arr,0,sizeof(arr));
	
	for(int i=0;i<=d1;i++){
		visited[y-i][x+i] = 1;
		visited[y+d2-i][x+d2+i] = 1;
		arr[0] += map[y-i][x+i] + map[y+d2-i][x+d2+i];
	}
	for(int i=1;i<d2;i++){
		visited[y+i][x+i] = 1;
		visited[y-d1+i][x+d1+i] = 1;
		arr[0] += map[y+i][x+i] + map[y-d1+i][x+d1+i];
	}
	for(int i=0;i<d1;i++){
		int j=0;
		while(!visited[y-i][x+i+j+1]){
			visited[y-i][x+i+j+1] = 1;
			arr[0] += map[y-i][x+i+j+1];
			j++;
		}
	}
	for(int i=0;i<d2;i++){
		int j=0;
		while(!visited[y+i][x+i+j+1]){
			visited[y+i][x+i+j+1] = 1;
			arr[0] += map[y+i][x+i+j+1];
			j++;
		}
	}
	
	for(int i=1;i<=n;i++){//y
		for(int j=1;j<=n;j++){//x
			if(visited[i][j]) continue;
			
			if(i<y && j<=x+d1) 	arr[1] += map[i][j];
			else if(i <= y-d1+d2 && x+d1<j) arr[2] += map[i][j];
			else if(y<=i && j<x+d2) arr[3] += map[i][j];
			else arr[4] += map[i][j];
		}
	}
	
	pair<int*, int*> p = minmax_element(arr,arr+5);
	answer = min(answer, *p.second-*p.first);
}

void div_area(){
	for(int x=1;x<n-1;x++){
		for(int y=1;y<n;y++){
			int d1=1;
			int d2=1;
			
			while(1){
				if(x+d1+d2 <= n && 1 <= y-d1 && y+d2 <= n) {
					count_area(x,y,d1,d2);
					d2++;
				}
				else {
					d1++;
					d2 = 1;
					if(!(x+d1+d2 <= n && 1 <= y-d1 && y+d2 <= n)) break;
				}
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin >> map[i][j];
		}
	}
	
	div_area();
	
	cout << answer << endl;
}
