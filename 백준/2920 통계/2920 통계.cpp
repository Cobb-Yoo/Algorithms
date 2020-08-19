#include <iostream>
using namespace std;

int main(){
	int arr[8];
	string condition = "";
	
	for(int i=0;i<8;i++) cin >> arr[i];
	
	for(int i=0;i<8;i++){
		if(arr[0] == 1) condition = "ascending";
		else if(arr[0] == 8) condition = "descending";
		else {
			condition = "mixed";
			break;
		}
		
		if(condition == "ascending" && arr[i] != i+1) {
			condition = "mixed";
			break;
		}
		else if(condition == "descending" && arr[i] != 8-i) {
			condition = "mixed";
			break;
		}
	}
	
	cout << condition << endl;
	
}
