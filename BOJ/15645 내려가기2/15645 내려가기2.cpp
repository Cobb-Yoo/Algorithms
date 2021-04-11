#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 100000+1;
int max_arr[2][3] = {0};
int min_arr[2][3] = {0};
int map[MAX][3];

int main(){
	int n;
	cin >> n;
	
	for(int i=0;i<n;i++){
		for(int j=0;j<3;j++){
			cin >> map[i][j];
		}
	}
	
	for(int i=0;i<3;i++){
		max_arr[0][i] = min_arr[0][i] = map[n-1][i];
	}
	
	for(int i=n-2;i>=0;i--){
		max_arr[1][0] = map[i][0] + max(max_arr[0][0], max_arr[0][1]);
		max_arr[1][1] = map[i][1] + max({max_arr[0][0], max_arr[0][1], max_arr[0][2]});
		max_arr[1][2] = map[i][2] + max(max_arr[0][1], max_arr[0][2]);
		
		min_arr[1][0] = map[i][0] + min(min_arr[0][0], min_arr[0][1]);
		min_arr[1][1] = map[i][1] + min({min_arr[0][0], min_arr[0][1], min_arr[0][2]});
		min_arr[1][2] = map[i][2] + min(min_arr[0][1], min_arr[0][2]);
		
		for(int j=0;j<3;j++){
			max_arr[0][j] = max_arr[1][j];
			min_arr[0][j] = min_arr[1][j];
		}
	}
	
	cout << max({max_arr[0][0],max_arr[0][1],max_arr[0][2]}) << " " << min({min_arr[0][0],min_arr[0][1],min_arr[0][2]});
}
