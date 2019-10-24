#include <iostream>
using namespace std;

int main(){
	int arr[10001]={0};
	int n;
	cin >> n;
	for(int i=0;i<n;i++){
		int t;
		scanf("%d",&t);
		arr[t]++;
	}
	for(int i=1;i<=10000;i++){
		for(int j=0;j<arr[i];j++){
			cout << i << '\n';
		}
	}
}
