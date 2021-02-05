#include <iostream>
#define ll long long
using namespace std;

const int Max = 100000;
int n;
ll cost[Max+1];
ll dist[Max+1];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	
	for(int i=0;i<n-1;i++) cin >> dist[i];
	for(int i=0;i<n;i++) cin >> cost[i];
	
	ll preCost=cost[0];
	ll totalCost = dist[0]*cost[0];
	int idx = 1;
	
	while(idx < n){
		if(preCost > cost[idx])	preCost = cost[idx];
		
		totalCost+= preCost*dist[idx++];
	}
	
	cout << totalCost;
}
