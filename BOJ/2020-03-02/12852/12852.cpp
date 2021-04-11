#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 1000000;
int arr[MAX+1];

void f(int n){
	if(!n) return;
	cout << n << " ";
	
	if(!(n%3) && (arr[n/3]+1) == arr[n]) f(n/3);
	else if(!(n%2) && (arr[n/2]+1) == arr[n]) f(n/2);
	else if(n-1 >= 0 && (arr[n-1]+1 == arr[n])) f(n-1);
}

int main(){
	cout.tie(0);
	ios_base::sync_with_stdio(false);
	
	int x;
	cin >> x;
	
	arr[2] = arr[3] = 1;
	
	for(int i=2;i<=x;i++){		
		arr[i]=arr[i-1]+1;
		if(!(i%2)) arr[i] = min(arr[i/2]+1,arr[i]);
		if(!(i%3)) arr[i] = min(arr[i/3]+1,arr[i]);
	}
	
	cout << arr[x] << endl;
	f(x);
}
