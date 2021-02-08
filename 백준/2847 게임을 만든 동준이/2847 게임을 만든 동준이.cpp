#include <iostream>
using namespace std;

int arr[101];
int n;

int main(){
	cin >> n;
	
	for(int i=0;i<n;i++) cin >> arr[i];
	
	int cnt = 0;
	for(int i=n-1;i>=0;i--){
		if(arr[i] < arr[i-1]){
			int tmp = arr[i-1] - arr[i]+1;
			arr[i-1] -= tmp;
			cnt += tmp;
		}
		else if(arr[i] == arr[i-1]){
			arr[i-1]--;
			cnt++;
		}
	}
	
	cout << cnt;
}
