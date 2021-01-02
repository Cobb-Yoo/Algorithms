#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;

const int MAX = 10000+1;
bool arr[MAX];
bool visited[MAX];
int start, terminal;
vector<int> v;

void init(){
	memset(arr,1,sizeof(arr));
	
	for(int i=2;i<=10000;i++){
		if(arr[i]){
			if(i > 1000) v.push_back(i);
			for(int j=i+i;j<=10000;j+=i){
				arr[j] = 0;
			}
		}
	}
}

void solve(){
	
	queue<pair<int,int>> q;
	q.push({start, 0});
	if(q.front().first == terminal) {
		cout << q.front().second << endl;
		return;
	}
	visited[start] = 1;
	
	while(!q.empty()){
		int num = q.front().first;
		int cnt = q.front().second;
		q.pop();
		
		int a = num - (num/1000)*1000;
		int b = num - ((num/100)%10)*100;
		int c = num - ((num/10)%10)*10;
		int d = num - num%10;
		
		for(int i=0;i<10;i++){
			if(arr[a+i*1000] && !visited[a+i*1000] && i != 0) {
				q.push({a+i*1000, cnt+1});
				visited[a+i*1000] = 1;
			}
			if(arr[b+i*100] && !visited[b+i*100]) {
				q.push({b+i*100, cnt+1});
				visited[b+i*100] = 1;
			}
			if(arr[c+i*10] && !visited[c+i*10]) {
				q.push({c+i*10, cnt+1});
				visited[c+i*10] = 1;
			}
			if(arr[d+i] && !visited[d+i]) {
				q.push({d+i, cnt+1});
				visited[d+i] = 1;
			}
			
			if(a+i*1000 == terminal || b+i*100 == terminal || c+i*10 == terminal || d+i == terminal){
				cout << cnt+1 << endl;
				return;
			}
		}
	}
	cout << "Impossible\n";
}

int main(){
	ios_base::sync_with_stdio(0);
	cout.tie(0);
	
	init();
	
	int t; cin >> t;
	
	while(t--){
		memset(visited,0,sizeof(visited));
		
		cin >> start >> terminal;
		
		solve();
	}
}
