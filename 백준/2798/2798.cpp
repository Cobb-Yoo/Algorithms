#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	int n,m;
	cin >> n >> m;
	
	int *arr = new int [n];
	
	int result = 0;
	
	for(int i=0;i<n;i++){
		cin >> arr[i];
	}
	
	sort(arr, arr+n);
	
	for(int i=0;i < n-2;i++){
		for(int j=i+1;j < n-1;j++){
			for(int k=j+1;k < n;k++){
 				int temp = arr[i] + arr[j] + arr[k];
				
				if(m < temp) break;
				
				if(result < temp) result = temp;
			}
		}
	}
	
	cout << result << endl;
	
	delete [] arr;
}
