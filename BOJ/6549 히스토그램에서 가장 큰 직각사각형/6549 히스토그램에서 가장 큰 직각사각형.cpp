#include <iostream>
#include <stack>
#define ll long long
using namespace std;

int main(){	
	while(1){
		int n;
		cin >> n;
		stack<ll> s;
		ll arr[100001]={0,};
		ll answer = 0;
		if(n==0) break;
		
		for(int i=1;i<=n;i++) cin >> arr[i];
		s.push(0);
		
		for(int i=1;i<=n+1;i++){
			while(!s.empty() && arr[s.top()] > arr[i]){
				ll height = s.top();
				s.pop();
				ll x = i - s.top() - 1;
				answer = max(answer, x*arr[height]);
			}
			s.push(i);
		}
		
		cout << answer << endl;
	}
}
