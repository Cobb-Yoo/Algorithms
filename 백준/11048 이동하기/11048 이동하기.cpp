#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	int n,m;
	cin >> n >> m;
	
	int arr[1001] = {0};
	
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			int tmp;
			cin >> tmp;
			
			arr[j] = max(arr[j],arr[j-1]) + tmp;
		}
	}
	
	cout << arr[m-1];
}
