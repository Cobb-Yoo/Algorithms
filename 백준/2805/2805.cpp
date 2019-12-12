#include <iostream>
#define ll long long
using namespace std;

ll arr[1000001]={};

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	cin >> n >> m;
	
	for(int i=0;i<n;i++){
		cin >> arr[i];
	}
	
	ll left=0;
	ll right=2000000000;
	ll max=0;
	
	while(left <= right){
		ll mid = (left + right) / 2;
		ll result = 0;
		
		for(int i=0;i<n;i++){
			if(mid < arr[i])
				result += arr[i] - mid;
		}
		
		if(result >= m){
			left = mid + 1;
			if(mid > max) max = mid;
		}
		else{
			right = mid - 1;
		}
	}
	
	cout << max << endl;
}
