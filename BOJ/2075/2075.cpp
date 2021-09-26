#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	priority_queue<int> pq;
	
	int n;
	int num;
	cin >> n;
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>> num;
			pq.push(-num);
			
			if(pq.size() > n) pq.pop();
		}
	}
	
	cout << -pq.top();
}
