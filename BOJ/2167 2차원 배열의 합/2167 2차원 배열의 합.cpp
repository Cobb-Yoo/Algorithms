#include <iostream>
#include <cstring>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n,m;
	cin >> n >> m;
	
	int arr[301][301]={0};
	
	int value;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin >> value;
			arr[i][j] = arr[i-1][j] + arr[i][j-1] + value - arr[i-1][j-1];
		}
	}
	
	int t;
	cin >> t;
	
	int answer;
	int a,b,x,y;
	while(t--){
		cin >> a >> b >> x >> y;
		
		cout << arr[x][y] - arr[a-1][y] - arr[x][b-1] + arr[a-1][b-1] << "\n";
	}
}
