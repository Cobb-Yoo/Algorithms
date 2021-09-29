#include <bits/stdc++.h>
using namespace std;

const int Max = 1000000000;

int main(){
	long long x, y;
	cin >> x >> y;
	
	int z = (y*100) / x;
	
	if(z >= 99) {
		cout << -1;
		return 0;
	}
	
	int low=0, high = Max;
	int result = -1;
	
	while(low <= high){
		int mid = (low+high)/2;
		
		int tmp = (100*(y + mid)) / (x + mid);
		
		if(z >= tmp){
			result = mid+1;
			low = mid+1;
		}
		else{
			high = mid-1;
		}
	}
	
	cout << result;
}
