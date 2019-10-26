#include <iostream>
using namespace std;

int main(){
	long long n;
	cin >> n;
	int arr[10]={0};
	
	while(n){
		arr[n%10]++;
		n/=10;
	}
	
	for(int i=9;i>=0;i--){
		for(int j=0;j<arr[i];j++){
			cout << i;
		}
	}
}
