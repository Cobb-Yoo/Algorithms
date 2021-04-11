#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

bool visited[1000001];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t; cin >> t;

	while(t--){
		memset(visited,0,sizeof(visited));
		
		int n; cin >> n;
		priority_queue<pair<int,int>> maxq;
		priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> minq;
		
		for(int i=0;i<n;i++){
			char oper;
			int num;
			
			cin >> oper >> num;
			
			if(oper == 'I'){
				minq.push({num, i});
				maxq.push({num, i});
				visited[i] = 1;
			}
			else{
				if(num == 1) {
					while(!maxq.empty() && !visited[maxq.top().second]) maxq.pop();
					
					if(!maxq.empty()){
						visited[maxq.top().second] = 0;
						maxq.pop();
					}
				}
				else {
					while(!minq.empty() && !visited[minq.top().second]) minq.pop();
					
					if(!minq.empty()){
						visited[minq.top().second] = 0;
						minq.pop();
					}
				}
			}
		}
		
		while(!maxq.empty() && !visited[maxq.top().second]) maxq.pop();
		while(!minq.empty() && !visited[minq.top().second]) minq.pop();
		
		if(maxq.empty() || minq.empty()) cout << "EMPTY\n";
		else cout << maxq.top().first << " " << minq.top().first << "\n";
	}	 
}
