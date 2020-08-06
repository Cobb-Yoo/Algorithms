#include <iostream>
#include <deque>
#include <string>
#include <queue>
using namespace std;

int main(){
	deque<int> dq[4];
	queue<pair<int,int>> q;
	
	for(int i=0;i<4;i++){
		string tmp; cin >> tmp;
		
		for(int j=0;j<8;j++) dq[i].push_back(tmp[j]-'0');
	}
	
	int n; cin >> n;
	for(int i=0;i<n;i++){
		int num, flag;
		cin >> num >> flag;
		
		int idx = num-1;
		int rotate = flag;
		
		q.push({idx,rotate});
		
		while(1){
			if(idx == 3) break;
			
			idx++;
			rotate *= -1;
			
			if(dq[idx-1][2] != dq[idx][6]) q.push({idx,rotate});
			else break;
		}
		
		idx = num-1;
		rotate = flag;
		
		while(1){
			if(idx == 0) break;
			
			idx--;
			rotate *= -1;
			
			if(dq[idx][2] != dq[idx+1][6]) q.push({idx,rotate});
			else break;
		}
		
		while(!q.empty()){
			int a = q.front().first;
			int b = q.front().second;
			q.pop();
			
			if(b == 1){
				int tmp = dq[a].back();
				dq[a].pop_back();
				dq[a].push_front(tmp);
			}
			else{
				int tmp = dq[a].front();
				dq[a].pop_front();
				dq[a].push_back(tmp);
			}
		}
	}
	
	int result = 0;
	for(int i=0;i<4;i++){
		if(dq[i].front() == 1){
			result += (1<<i);
		}
	}
	
	cout << result << endl;
	
	for(int i=0;i<4;i++){
		for(int j=0;j<8;j++){
			cout << dq[i][j];
		}
		cout << endl;
	}
}
