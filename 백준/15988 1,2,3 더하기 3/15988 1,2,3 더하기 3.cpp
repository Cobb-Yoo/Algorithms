#include <iostream>
#define ll long long
using namespace std;

ll arr[1000001];

void init(){
	arr[1] = 1;
	arr[2] = 2;
	arr[3] = 4;
	
	for(int i=4;i<=1000000;i++){
		arr[i] = (arr[i-1] + arr[i-2] + arr[i-3]) % 1000000009;
	}
}

int main(){
	int n;
	cin >> n;
	
	init();
	
	for(int i=0;i<n;i++){
		int num; cin >> num;
		cout << arr[num] << "\n";
	}
}
