#include <iostream>
using namespace std;

int arr[101];
int brr[101];

int main(){
	int result = 0;
	int n,k;
	cin >> n >> k;
	
	for(int i=0;i<k;i++) cin >> arr[i];
	
	for(int i=0;i<k;i++){
		bool flag = false;
		
		for(int j=0;j<n;j++){
			if(brr[j] == arr[i]){
				flag = true;
				break;	
			}
		}
		
		if(flag) continue;
		
		for(int j=0;j<n;j++){
			if(brr[j] == 0){
				brr[j] = arr[i];
				flag = true;
				break;
			}
		}
		
		if(flag) continue;
		
		int idx, deviceidx = -1;
		for(int j=0;j<n;j++){
			int lastidx = 0;
			
			for(int l=i+1;l<k;l++){
				if(brr[j] == arr[l]) break;
				lastidx++;
			}
			
			if(lastidx > deviceidx){
				idx=j;
				deviceidx = lastidx;
			}
		}
		
		result++;
		brr[idx] = arr[i];
	}
	
	cout << result << endl;
}
