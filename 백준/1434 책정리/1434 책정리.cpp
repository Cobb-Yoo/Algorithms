#include <iostream>
using namespace std;

int arr[51];
int n,m;

int main(){
	cin >> n >> m;
	
	int ans=0, idx=0;
	for(int i=0;i<n;i++){
		cin >> arr[i];
	}
	
	for(int tmp,i=0;i<m;i++){
		cin >> tmp;
		
		while(1) {
			if(arr[idx] >= tmp){
				arr[idx] -= tmp;
				break;
			}
			else ans += arr[idx++];
		}
	}
	
	for(int i=idx;i<n;i++) ans += arr[i];
	
	cout << ans;
}
