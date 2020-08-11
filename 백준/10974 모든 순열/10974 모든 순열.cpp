#include <iostream>
#include <algorithm>
using namespace std;

int arr[9];

int main(){	
	for(int i=0;i<=8;i++) arr[i] = i;
	int n; cin >> n;
	
	do{
		for(int i=1;i<=n;i++) cout << arr[i] << " ";
		cout << "\n";
	}while(next_permutation(arr+1, arr+n+1));
}
