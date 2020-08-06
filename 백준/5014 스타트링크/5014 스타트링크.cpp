#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int f,s,g,u,d;
int arr[1000001];

int bfs(){
	if(s == g) return 1;
	
	queue<int> q;
	q.push(s);
	arr[s] = 0;
	
	while(!q.empty()){
		int now = q.front();
		q.pop();
		
		if(now == g) return arr[now];
		
		int nextY[2] = {now+u, now-d};
		for(int i=0;i<2;i++){
			if(1<=nextY[i]&&nextY[i]<=f && arr[nextY[i]]==-1){
				arr[nextY[i]] = arr[now]+1;
				q.push(nextY[i]);
			}
		}
	}
	
	return -1;
}
int main(){
	cin >> f >> s >> g >> u >> d;
	memset(arr,-1,sizeof(arr));
	
	int result = bfs();
	if(result==-1) cout << "use the stairs" << endl;
	else cout << result << endl;
}
