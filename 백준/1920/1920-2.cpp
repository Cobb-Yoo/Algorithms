#include <iostream>
#include <algorithm>
#define MAX 100001
using namespace std;

int arr[MAX];
int brr[MAX];

int solue(int start,int end, int key){
	int mid = (end+start)/2;
	
	if(end<start) return 0;
	
	if(key==arr[mid]){
		return 1;
	}
	else if(key > arr[mid]){
		return solue(mid+1,end,key);
	}
	else{
		return solue(start,mid-1,key);
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
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
		cout << solue(0,a-1,brr[i]) << "\n";
	}
}
