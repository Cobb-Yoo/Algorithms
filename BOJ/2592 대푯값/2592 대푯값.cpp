#include <iostream>
using namespace std;

int arr[101];

int main(){
	int avg=0;
	int n;
	for(int i=0;i<10;i++){
		cin >> n;
		
		avg += n;
		arr[n/10]++;
	}
	
	int m = arr[0];
	for(int i=1;i<=100;i++){
		if(m < arr[i]){
			m = i;
		}
	}
	
	cout << avg / 10 << endl << m*10 << endl;
}
