#include <iostream>
using namespace std;

int arr[41];
int brr[41];

void init(){
	arr[1] = 1;
	arr[2] = 2;
	
	for(int i=3;i<41;i++) arr[i] = arr[i-1] + arr[i-2];
}

int main(){
	long long answer = 1;
	int n, m;
	cin >> n >> m;
	
	init();
	
	brr[0] = 0;
	for(int i=1;i<=m;i++) cin >> brr[i];
	
	for(int i=1;i<=m;i++) if(arr[brr[i] - brr[i-1]-1]) answer *= arr[brr[i] - brr[i-1]-1];
	
	if(brr[m] != n) answer *= arr[n - brr[m]];
	
	cout << answer << endl;
}

