#include <iostream>
#include <deque>
using namespace std;

const int MAX = 5000000;

int arr[MAX];
deque<pair<int,int>> dq;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n,l;
	cin >> n >> l;
	
	for(int i=0;i<n;i++) cin >> arr[i];
	
	for(int i=0;i<n;i++){
		if(!dq.empty() && dq.front().second <= i-l)
			dq.pop_front();
		
		while(!dq.empty() && dq.back().first > arr[i])
			dq.pop_back();
		
		dq.push_back({arr[i],i});
		cout << dq.front().first << " ";
	}
}
