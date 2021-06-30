#include <bits/stdc++.h>
using namespace std;

int arr[101];
int n;

int main(){
	cin >> n;
	
	for(int i=1;i<=n;i++){
		cin >> arr[i];
	}
	
	int t; cin >> t;
	
	for(int i=0;i<t;i++){
		int sex, button;
		cin >> sex >> button;
		
		if(sex == 1) {
			for(int j=button;j<=n;j+=button) arr[j] = !arr[j];
		}
		else if(sex == 2){
			arr[button] = !arr[button];
			
			int left = button-1, right = button+1;
			
			while(left>=1 && right<=n){
				if(arr[left] == arr[right]) {
					arr[left] = !arr[left];
					arr[right] = !arr[right];
					left--;
					right++;
				}
				else break;
				
				
			}
		}
	}
	
	for(int i=1;i<=n;i++) {
		cout << arr[i] << " ";
		if(i%20 == 0) cout << endl;
	}
}
