#include <iostream>
using namespace std;

int versus(int *a, int *b){
	if(a[4] > b[4]){
		return 1;
	}
	else if(a[4] == b[4]){
		if(a[3] > b[3]){
			return 1;
		}
		else if(a[3] == b[3]){
			if(a[2] > b[2]){
				return 1;
			}
			else if(a[2] == b[2]){
				if(a[1] > b[1]){
					return 1;
				}
				else if(a[1] == b[1]){
					return 3;
				}
			}
		}
	}
	return 2;
}

int main(){
	int n; cin >> n;
	
	while(n--){
		int a,b,tmp;
		int arr[5]={0};
		int brr[5]={0};
		
		cin >> a;
		for(int i=0;i<a;i++){
			cin >> tmp;
			arr[tmp]++;
		}
		
		cin >> b;
		for(int i=0;i<b;i++){
			cin >> tmp;
			brr[tmp]++;
		}
		
		int result = versus(arr, brr);
		
		if(result == 1) cout << "A\n";
		else if(result == 2)cout << "B\n";
		else if(result == 3)cout << "D\n";
	}
}
