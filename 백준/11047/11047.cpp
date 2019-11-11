#include <iostream>
using namespace std;

int main(){
	int n,k;
	cin >> n >> k;
	int count=0;
	
	int arr[n];
		
	for(int i=0;i<n;i++){
		cin >> arr[i];
	}
	
	int tmp = n-1;
	
	while(true){
		if(k == 0) break;
		
		if(k - arr[tmp] >= 0) {
			k -= arr[tmp];
			count++;
		}
		else tmp--;
		
	}
	
	cout << count << endl;
}
