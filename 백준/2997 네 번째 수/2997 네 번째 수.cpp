#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;

int main(){
	vector<int> arr(3);
	
	for(int i=0;i<3;i++) cin >> arr[i];
	sort(arr.begin(), arr.end());
	
	if(arr[1]-arr[0] == arr[2]-arr[1]){
		cout << arr[2] + arr[1]-arr[0] << endl;
	}else if(arr[1]-arr[0] > arr[2]-arr[1]){
		cout << arr[0] + arr[2]-arr[1] << endl;
	}else{
		cout << arr[1] + arr[1]-arr[0] << endl;
	}
}
