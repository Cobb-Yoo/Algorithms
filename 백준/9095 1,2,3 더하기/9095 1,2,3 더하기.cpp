#include <iostream>
#include <cstring>
using namespace std;

int arr[12];

void init(){
	arr[1] = 1;
	arr[2] = 2;
	arr[3] = 4;
	
	for(int i=4;i<12;i++){
		arr[i] = arr[i-1]+arr[i-2]+arr[i-3];
	}
}

int main(){
	int n;
	cin >> n;
	init();
	
	while(n--){
		int tmp;
		cin >> tmp;
		
		cout << arr[tmp] << endl;
	}
}
