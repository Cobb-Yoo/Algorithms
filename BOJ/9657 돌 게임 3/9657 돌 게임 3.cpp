#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

int n;
int arr[1001];

void stone(){
	memset(arr,-1,sizeof(arr));
	
	arr[1] = 1;
	arr[2] = 0;
	arr[3] = 1;
	arr[4] = 1;
	
	for(int i=5;i<=1000;i++){
		if(min({arr[i-1],arr[i-3],arr[i-4]}) == 1) arr[i] = 0;
		else arr[i] = 1;
		
		if(i == n) break;
	}
}

int main(){
	cin >> n;
	
	stone();
	
	if(arr[n]) cout << "SK";
	else cout << "CY";
}
