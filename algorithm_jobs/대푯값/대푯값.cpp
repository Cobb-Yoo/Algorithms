#include <iostream>
using namespace std;

int arr[101];

int main(){
	int sum;
	for(int tmp,i=0;i<10;i++){
		cin >> tmp;
		arr[tmp/10]++;
		sum += tmp;
	}
	cout << sum/10 << endl;
	
	int Max=0;
	int idx=0;
	for(int i=1;i<=100;i++){
		if(Max < arr[i]){
			Max = arr[i];
			idx = i*10;
		}
	}
	cout << idx;
}
