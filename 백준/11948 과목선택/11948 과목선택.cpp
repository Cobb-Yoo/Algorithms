#include <iostream>
using namespace std;

int main(){
	int arr[6];
	int answer = 0;
	for(int i=0;i<6;i++){
		cin >> arr[i];
		answer += arr[i];
	}
	
	int MIN = 101;
	for(int i=0;i<4;i++){
		MIN = min(arr[i], MIN);
	}
	
	answer -= MIN;
	
	if(arr[4] > arr[5]) answer -= arr[5];
	else answer -= arr[4];
	
	cout << answer << endl;
}
