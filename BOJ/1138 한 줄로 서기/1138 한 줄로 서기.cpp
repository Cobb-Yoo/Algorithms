#include <iostream>
#include <vector>
using namespace std;

int main(){
	int n;
	cin >> n;
	int left;
	int arr[10]={0};
	
	for(int i=0;i<n;i++){
		cin >> left;
		
		for(int j=0;j<n;j++){
			if(!left && arr[j] == 0){
				arr[j] = i+1;
				break;
			}
			else if(arr[j] == 0) left--;
		}
	}
	
	for(int i=0;i<n;i++) cout << arr[i] << " ";
}
