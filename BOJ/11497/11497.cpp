#include <iostream>
#include <deque>
#include <algorithm>
#include <cmath>
using namespace std;

const int Max = 10000;
int n;
int arr[Max+1];

int main(){
	int t; cin >> t;
	
	while(t--){
		cin >> n;
		for(int i=0;i<n;i++) cin >> arr[i];
		
		sort(arr, arr+n);
		
		deque<int> dq;
		dq.push_back(arr[0]);
		
		for(int i=1;i<n;i++){
			if(i&1) dq.push_back(arr[i]);
			else dq.push_front(arr[i]);
		}
		
		int answer = 0;
		for(int i=0;i<n;i++){
			answer = max(answer, abs(dq[i%n]-dq[(i+1)%n]));
		}
		
		cout << answer << endl;
	}
}
