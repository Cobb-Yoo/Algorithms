#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main(){
	int n; cin >> n;
	
	priority_queue<int, vector<int>, greater<int>> pq;
	
	if(n == 1) {
		cout << 0;
		return 0;
	}
	
	for(int tmp,i=0;i<n;i++){
		cin >> tmp;
		pq.push(tmp);
	}
	
	int sum=0;
	
	while(!pq.empty()){
		int a = pq.top();
		pq.pop();
		int b = pq.top();
		pq.pop();
		
		sum += a+b;
		
		if(pq.empty()) break;
		
		pq.push(a+b);
	}
	
	cout << sum;
}

