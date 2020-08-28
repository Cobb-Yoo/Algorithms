#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	int arr[4]={0};
	int n; cin >> n;
	
	while(n--){
		int tmp;
		for(int i=3;i>=1;i--) {
			cin >> tmp;
			arr[tmp] += i;
		}
	}
	sort(arr,arr+4);
	for(int i=0;i<4;i++) cout << arr[i] << " ";
	cout << endl;
	if(arr[3] == arr[2]) cout << 0 << endl;
	else cout << arr[3] << endl;
}
