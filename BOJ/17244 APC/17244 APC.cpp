#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n,l,k;
vector<int> v;

int main(){
	cin >> n >> l >> k;
	
	int ans = 0;
	
	for(int a,b,i=0;i<n;i++){
		if(!k) break;
		cin >> a >> b;
		
		if(b <= l){
			ans += 140;
			k--;
		}
		else if(a <= l){
			v.push_back(a);
		}
	}
	
	
	int len = v.size();
	
	for(int i=0;i<len;i++){
		if(!k) break;
		
		ans += 100;
		k--;
	}
	
	cout << ans;
}
