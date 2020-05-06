#include <iostream>
#include <queue>
using namespace std;

int main(){
	int n,cnt=0;
	cin >> n;
	
	int arr[n+1][n+1];
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin >> arr[i][j];
		}
	}
	
	queue<pair<int,int>> q;
	q.push({1,1});
	
	while(!q.empty()){
		int x = q.front().first;
		int y = q.front().second;
		int tmp = arr[x][y];
		q.pop();
		
		if(tmp+x <= n){
			if(x+tmp == n && y == n) cnt++;
			else q.push({x+tmp,y});	
		} 
		if(tmp+y <= n){
			if(x == n && y+tmp == n) cnt++;
			else q.push({x,y+tmp});	
		} 
		
		
	}
	
	cout << cnt << endl;
}
