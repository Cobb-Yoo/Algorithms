#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	int n,k;
	cin >> n >> k;
	
	int left=1, right=k, mid;
	int answer;
	
	while(left<=right){
		int cnt=0;
		mid = (left + right) / 2;
		for(int i=1;i<=n;i++) cnt += min(mid/i,n);
		
		if(cnt < k) left = mid+1;
		else answer = mid, right = mid-1;
	}
	cout << answer << endl;
}
