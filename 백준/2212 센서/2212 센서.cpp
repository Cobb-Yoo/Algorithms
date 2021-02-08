#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	int n,k;
	cin >> n >> k;
	
	vector<int> v(n);
	for(int i=0;i<n;i++) cin >> v[i];
	
	sort(v.begin(), v.end());
	
	int *dif = new int[n-1];
	for(int i=0;i<n-1;i++) dif[i] = v[i+1] - v[i];
	
	sort(dif, dif+n-1);
	
	int ans = 0;
	for(int i=0;i<n-k;i++) ans += dif[i];
	
	cout << ans;
}
