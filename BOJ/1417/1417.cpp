#include <bits/stdc++.h>
using namespace std;

int main(){
	int n; cin >> n;
	priority_queue<int> pq;
	int dasom; cin >> dasom;
	int answer = 0;
	
	for(int tmp,i=1;i<n;i++){
		cin >> tmp;
		pq.push(tmp);
	}
	
	while(1){
		int tmp = pq.top();
		pq.pop();
		
		if(dasom <= tmp){
			dasom++;
			pq.push(tmp-1);
			answer++;
		}
		else break;
	}
	
	cout << answer << endl;
}
