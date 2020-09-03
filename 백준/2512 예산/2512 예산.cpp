#include <iostream>
#include <vector>
using namespace std;

int main(){
	int n;
	int money;
	
	cin >> n;
	vector<int> v(n);
	
	int right=0;
	for(int i=0;i<n;i++){
		cin >> v[i];
		right = max(right, v[i]);
	} 
	
	cin >> money;
	
	int left = 0;
	int answer;
	
	while(left<=right){
		int mid = (left+right)/2;
		
		int sum=0;
		for(int i=0;i<n;i++){
			sum += min(v[i], mid);
		}
		
		if(sum <= money){
			answer = mid;
			left = mid+1;
		}else{
			right = mid-1;
		}
	}
	
	cout << answer << endl;
}
