#include <iostream>
#include <algorithm>
#define MAX 100001
using namespace std;

int arr[MAX];
int brr[MAX];

void solue(int n, int key){
	int start = 0;
	int end = n -1;
	
	while(end-start >= 0){
		int mid = (start + end) / 2;
		if(key == arr[mid]){
			cout << "1\n";
			return;
		}
		else if(key < arr[mid]){
			end = mid-1;
		}
		else{
			start = mid+1;
		}
	}
	
	cout << "0\n"; 
}

int main(){
	int a,b;
	cin >> a;
	
	for(int i=0;i<a;i++){
		cin >> arr[i];
	}
	
	cin >> b;
	for(int i=0;i<b;i++){
		cin >> brr[i];
	}
	
	sort(arr,arr+a);
	
	for(int i=0;i<b;i++){
		solue(a,brr[i]);
	}
}
