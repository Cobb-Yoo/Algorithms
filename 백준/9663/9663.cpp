#include <iostream>
using namespace std;

int n;
int count=0;
int arr[15];

bool check(int x){
	for(int i=0;i<x;i++){
		if(arr[i]==arr[x] || abs(arr[i]-arr[x]) == x-i){
			return false;
		}
	}
	return true;
}

void nqueen(int cnt){
	if(cnt == n){
		count++;
	}
	else{
		for(int i=0;i<n;i++){
			arr[cnt] = i;
			if(check(cnt)) nqueen(cnt+1);
		}
	}
}

int main(){
	cin >> n;
	
	nqueen(0);
	
	cout << count;
}
