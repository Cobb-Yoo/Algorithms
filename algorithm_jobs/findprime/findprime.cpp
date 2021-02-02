#include <iostream>
#include <cstring>
using namespace std;

bool arr[1001];

void init(){
	memset(arr,1,sizeof(arr));
	
	arr[1] = 0;
	for(int i=2;i*i<=1000;i++){
		if(arr[i]){
			for(int j=i+i;j<=1000;j+=i){
				arr[j] = 0;
			}
		}
	}
}

int main(){
	init();
	int n; cin >> n;
	int cnt = 0;
	
	for(int tmp,i=0;i<n;i++){
		cin >> tmp;
		if(arr[tmp]) cnt++;
	}
	
	cout << cnt;
}
