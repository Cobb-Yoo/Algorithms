#include <bits/stdc++.h>
using namespace std;

int arr[101];
int event[101];

int main(){
	memset(arr,-1,sizeof(arr));
	int n,m;
	cin >> n >> m;
	
	for(int a,b,i=0;i<n+m;i++){
		cin >> a >> b;
		event[a] = b;
	}
	
	queue<int> q;
	q.push(1);
	arr[1] = 0;
	
	while(!q.empty()){
		int y = q.front();
		q.pop();
		
		for(int i=1;i<7;i++){
			int ny = y+i;
			if(ny > 100) break;
		
			if(event[ny]) ny = event[ny];
			
			if(arr[ny]==-1){
				arr[ny] = arr[y]+1;
				q.push(ny);
			}
		}
	}
	
	cout << arr[100];
}
