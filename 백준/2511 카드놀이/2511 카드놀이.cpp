#include <iostream>
using namespace std;

int main(){
	int arr[10];
	int brr[10];
	int a=0, b=0;
	
	for(int i=0;i<10;i++) cin >> arr[i];
	for(int i=0;i<10;i++) cin >> brr[i];
	
	for(int i=0;i<10;i++){
		if(arr[i] < brr[i]) b+=3;
		else if(arr[i] > brr[i]) a+=3;
		else {
			a+=1;
			b+=1;
		}
	}
	
	cout << a << " " << b << endl;
	
	if(a == b){
		int i;
		for(i=9;i>=0;i--){
			if(arr[i] > brr[i]) {
				cout << "A\n";
				break;
			}
			else if(arr[i] < brr[i]) {
				cout << "B\n";
				break;
			}
		}
		if(i == -1) cout << "D\n";
	}
	else if(a > b) cout << "A\n";
	else cout << "B\n";
}
