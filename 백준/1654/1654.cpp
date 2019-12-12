#include <iostream>
#include <climits>
#define ll long long
using namespace std;

ll arr[10001]={};

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n, count;
	cin >> n >> count;
	
	for(int i=0;i<n;i++){
		cin >> arr[i];
	}
	
	ll left=0;
	ll right= LLONG_MAX;
	ll max = 0;
	while(left<=right){
		ll result=0;
		ll mid = (left + right) / 2;
		
		for(int i=0;i<n;i++){
			result += arr[i] / mid;
		}
		
		if(result >= count){
			left = mid + 1;
			if(mid > max) max = mid;
		}
		else{
			right = mid - 1;
		}
	}
	
	cout << max << endl;
}
