#include <iostream>
#include <algorithm>
using namespace std;

int arr[3];
int dp_min[3][2];
int dp_max[3][2];
	
int main(){
	int n;
	cin >> n;	
	
	for(int i=1;i<=n;i++){
		for(int j=0;j<3;j++) cin >> arr[j];
		
		dp_min[0][1] = arr[0] + min(dp_min[0][0],dp_min[1][0]);
		dp_min[1][1] = arr[1] + min({dp_min[0][0],dp_min[1][0],dp_min[2][0]});
		dp_min[2][1] = arr[2] + min(dp_min[1][0],dp_min[2][0]);
		
		dp_max[0][1] = arr[0] + max(dp_max[0][0],dp_max[1][0]);
		dp_max[1][1] = arr[1] + max({dp_max[0][0],dp_max[1][0],dp_max[2][0]});
		dp_max[2][1] = arr[2] + max(dp_max[1][0],dp_max[2][0]);
		
		for(int j=0;j<3;j++){
			dp_min[j][0] = dp_min[j][1];
			dp_max[j][0] = dp_max[j][1];
		}
	}
		
	cout << max({dp_max[0][0],dp_max[1][0],dp_max[2][0]}) << " " << min({dp_min[0][0],dp_min[1][0],dp_min[2][0]}) << endl;
}
