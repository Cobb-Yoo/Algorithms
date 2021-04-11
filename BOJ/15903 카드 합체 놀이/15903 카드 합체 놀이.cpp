#include <iostream>
#include <queue>
#include <vector>
#define ll long long 
using namespace std;

int main(){
	int n,m;
	cin >> n >> m;
	
	priority_queue<ll, vector<ll>, greater<ll>> pq;
	 
	for(int tmp,i=0;i<n;i++){
		cin >> tmp;
		pq.push(tmp);
	}
	
	for(int i=0;i<m;i++){
		ll a,b;
		a = pq.top(); pq.pop();
		b = pq.top(); pq.pop();
		
		pq.push(a+b);
		pq.push(a+b);
	}
	
	ll sum=0;
	while(!pq.empty()){
		sum += pq.top();
		pq.pop();
	}
	
	cout << sum;
}
