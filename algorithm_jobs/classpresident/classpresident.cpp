#include <iostream>
using namespace std;

int arr[1001][6];
bool check[1001][1001];

int main(){
	int n; cin >> n;
	
	for(int i=0;i<n;i++){
		for(int j=0;j<5;j++){
			cin >> arr[i][j];
		}
	}
	
	for(int i=0;i<5;i++){
		for(int j=0;j<n-1;j++){
			for(int k=j+1;k<n;k++){
				if(arr[j][i] == arr[k][i]){
					check[j][k] = 1;
					check[k][j] = 1;
				}
			}
		}
	}
	
	int answer = -1;
	int cnt = -1;
	
	for(int i=0;i<n;i++){
		int count=0;
		
		for(int j=0;j<n;j++){
			if(check[i][j]) count++;
		}
		
		if(cnt < count){
			answer = i+1;
			cnt = count;
		}
	}
	
	cout << answer;
}
