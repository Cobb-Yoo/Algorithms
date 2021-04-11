#include <iostream>
using namespace std;

const int MAX = 100;

int arr[MAX][MAX];
int brr[MAX][MAX];
int crr[MAX][MAX];
int n,m;

int main(){
	cin >> n >> m;
	
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin >> arr[i][j];
		}
	}
	
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin >> brr[i][j];
		}
	}
	
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			crr[i][j] = arr[i][j] + brr[i][j];
			cout << crr[i][j] << " ";
		}
		cout << endl;
	}
}
