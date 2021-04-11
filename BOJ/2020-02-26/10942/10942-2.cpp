#include <iostream>
#include <cstring>
using namespace std;

int arr[2001];
bool check[2001][2001];
int n;

void f(){
	for(int i=1;i<=n;i++){
		check[i][i] = true;
	}
	
	for(int i=1;i<n;i++){
		if(arr[i] == arr[i+1]) check[i][i+1] = true;
	}
	
	for(int i=2;i<n;i++){
		for(int j=1;j<=n-i;j++){
			if(arr[j] == arr[j+i] && check[j+1][j+i-1])
				check[j][j+i] = true;
		}
	}
}

int main(){
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> n;
	
	for(int i=1;i<=n;i++){
		cin >> arr[i];
	}
	
	memset(check,false,sizeof(check));
	f();
	
	int m;
	cin >> m;
	
	int a,b;
	for(int i=0;i<m;i++){
		cin >> a >> b;
		cout << check[a][b] << "\n";
	}
}
