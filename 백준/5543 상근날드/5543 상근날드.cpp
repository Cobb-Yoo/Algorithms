#include <iostream>
#include <algorithm>
using namespace std;

main(){
	int arr[5];
	
	for(int i=0;i<5;i++){
		cin >> arr[i];
	}
	
	cout << min({arr[0],arr[1],arr[2]}) + min(arr[3],arr[4]) - 50 << endl;
}
