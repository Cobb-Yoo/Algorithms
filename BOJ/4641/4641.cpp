#include <bits/stdc++.h>
using namespace std;

bool arr[101];

int main(){
	int tmp;
	
	while(cin >> tmp && tmp != -1){
		memset(arr,0,sizeof(arr));
		arr[tmp] = 1;
		
		int n;
		while(cin >> n && n){
			arr[n]=1;
		}
		
		int idx=0;
		for(int i=1;i<=50;i++){
			if(arr[i]){
				if(arr[i*2]) {
					idx++;
				}
			}
		}
		cout << idx << endl;
	}
}
