#include <iostream>
#include <cmath>
using namespace std;

int main(){
	int m,n;
	bool arr[1000000];
	cin >> m >> n;
	
	for(int i=2;i<=n;i++){//1을 제외한 범위내 모든 불린 참으로 초기화 
		arr[i] = true;
	}
	
	for(int i=2;i*i<=n;i++){
		if(arr[i]){
			for(int j=i*i;j<=n;j+=i){
				arr[j] = false;
			}
		}
	}
	
	for(int i=m;i<=n;i++){
		if(arr[i]) cout << i << '\n';
	}
}
