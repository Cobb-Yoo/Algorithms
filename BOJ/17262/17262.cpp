#include <iostream>
using namespace std;

int main(){
	int n; cin >> n;
	
	int left, right;
	cin >> left >> right;
	
	for(int s,e,i=1;i<n;i++){
		cin >> s >> e;
		
		left = max(left, s);
		right = min(right, e);
	}
	
	int ans = left - right;
	
	if(ans < 0) cout << 0;
	else cout << ans;
}
