#include <iostream>
using namespace std;

int map[101][101];
int arr[101];
int main(){
	int n; cin >> n;
	
	for(int a,b,y,x,t=1;t<=n;t++){
		cin >> a >> b >> y >> x;
		
		for(int i=a;i<a+y;i++){
			for(int j=b;j<b+x;j++){
				map[i][j] = t;
			}
		}
	}
	
	for(int i=0;i<=100;i++){
		for(int j=0;j<=100;j++){
			arr[map[i][j]]++;
		}
	}
	
	for(int i=1;i<=n;i++) cout << arr[i] << endl;
}
