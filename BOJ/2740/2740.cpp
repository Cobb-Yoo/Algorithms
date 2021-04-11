#include <iostream>
#define MAX 100
using namespace std;

int arr_a[MAX][MAX];
int arr_b[MAX][MAX];
int arr_c[MAX][MAX];

int main(){
	int n,m,k;
	
	cin >> n >> m;
	
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin >> arr_a[i][j];
		}
	}
	
	cin >> m >> k;
	for(int i=0;i<m;i++){
		for(int j=0;j<k;j++){
			cin >> arr_b[i][j];
		}
	}
	
	for(int i=0;i<n;i++){
		for(int j=0;j<k;j++){
			for(int l=0;l<m;l++){
				arr_c[i][j] += arr_a[i][l] * arr_b[l][j];
			}
		}
	}
	
	for(int i=0;i<n;i++){
		for(int j=0;j<k;j++){
			cout << arr_c[i][j] << ' ';
		}
		cout << endl;
	}
}
