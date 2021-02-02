#include <iostream>
using namespace std;

int arr[1000001];
int brr[1000001];

void init(){
	for(int i=1;i<1000001;i++){
		if(i%5 == 0) {
			int cnt = 0, tmp = i;
			while(tmp%5 == 0){
				tmp /= 5;
				cnt++;
			}
			arr[i] = arr[i-1] + cnt;
		}
		else arr[i] = arr[i-1];
	}
	
	for(int i=1;i<1000001;i++){
		if(i%2 == 0) {
			int cnt = 0, tmp = i;
			while(tmp%2 == 0){
				tmp /= 2;
				cnt++;
			}
			brr[i] = brr[i-1] + cnt;
		}
		else brr[i] = brr[i-1];
	}
}

int main(){
	init();
	
	int a,b;
	cin >> a >> b;
	
	if(arr[a] - arr[b] - arr[a-b] > brr[a] - brr[b] - brr[a-b] ) cout << brr[a] - brr[b] - brr[a-b];
	else cout << arr[a] - arr[b] - arr[a-b];
}
