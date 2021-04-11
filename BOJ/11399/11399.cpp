#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	int n;
	cin >> n;
	
	int arr[n+1] = {0};
	
	for(int i=1;i<=n;i++){
		cin >> arr[i];
	}
	
	sort(arr+1, arr+n+1);
	
	int sum=0;
	
	for(int i=1;i<=n;i++){
		arr[i] += arr[i-1];
		
		sum += arr[i];
	}
	
	cout << sum << endl;
}
