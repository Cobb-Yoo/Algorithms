#include <iostream>
#include <algorithm>
#include <vector>
#define ll long long
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n,m;
	cin >> n >> m;
	vector<ll> v(n);
	
	for(int i=0;i<n;i++){
		cin >> v[i];
	}
	
	sort(v.begin(), v.end());
	
	ll tmp;
	for(int i=0;i<m;i++){
		cin >> tmp;
		int right = n-1;
		int left = 0;
		int mid;
	
		bool flag = 1;
		int idx;
		while(left < right){
			mid = (left+right)/2;
		
			if(v[mid] == tmp){
				flag = 0;
				idx = mid;
				right = mid;
			}
			else if(v[mid] < tmp) left = mid+1;
			else right = mid;
			
			if(left == right){
				if(v[left] == tmp){
					flag = 0;
					idx = left;
				}
			}
		}
		if(flag) cout << -1 << "\n";
		else cout << idx << "\n";
	}
}
