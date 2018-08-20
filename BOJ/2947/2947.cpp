#include<bits/stdc++.h>
using namespace std;

int arr[5];

void printing(){
	for(int i=0;i<5;i++){
		cout << arr[i] << " ";
	}
	cout << endl;
}

void swap(int &a, int &b){
	int tmp = a;
	a = b;
	b = tmp;
}

int main(){
	for(int i=0;i<5;i++){
		cin >> arr[i];
	}
	
LOOP :
	for(int i=0;i<4;i++){
		if(arr[i] > arr[i+1]){
			swap(arr[i], arr[i+1]);
			printing();
			goto LOOP;
		}
	}
}
