#include <iostream>
#define ll long long
using namespace std;

ll arr[101], brr[101];

int main(){
	int n; cin >> n;
	
	for(int i=0;i<n;i++) cin >> brr[i];
	
	arr[0] = brr[0];
	for(int i=0;i<n;i++){
		int tmp = brr[i]*(i+1);
		
		int sum=0;
		for(int j=0;j<i;j++){
			sum += arr[j];
		}
		
		arr[i] = tmp - sum;
	}
	
	for(int i=0;i<n;i++){
		cout << arr[i] << " ";
	}
}
