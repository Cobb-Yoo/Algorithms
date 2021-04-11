#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int cnt=0;
int si,sj;
int ei,ej;
int n;
int arr[301][301];

int option[8][2] = {{-2,1},{-1,2},{1,2},{2,1},{2,-1},{1,-2},{-1,-2},{-2,-1}};

void f(){
	if(si == ei && sj == ej) return;
	queue<pair<int,int>> q;
	q.push({si,sj});
	arr[si][sj] = 0;
	
	while(!q.empty()){
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		
		for(int i=0;i<8;i++){
			int next_y = y + option[i][0];
			int next_x = x + option[i][1];
			
			if(0<=next_y&&next_y<n && 0<=next_x&&next_x<n){
				if(arr[next_y][next_x] == -1){
					arr[next_y][next_x] = arr[y][x]+1;
					if(next_y == ei && next_x == ej) {
						cnt = arr[next_y][next_x];
						break;
					}
					q.push({next_y, next_x});
				}
			}
		}
	}
}


int main(){
	int t;
	cin >> t;
	
	while(t--){
		cin >> n;
		memset(arr,-1,sizeof(arr));
		
		cin >> si >> sj >> ei >> ej;
		cnt=0;
		
		f();
		
		cout << cnt << endl;
	}
}
