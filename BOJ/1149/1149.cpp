#include <iostream>
using namespace std;

int MIN(int a, int b){
	if(a<b) return a;
	else return b;
}

int main(){
	int arr[1001][3]={0};
	int cal_arr[1001][3] = {0};
	int n;
	cin >> n;
	
	for(int i=1;i<=n;i++){
		for(int j=0;j<3;j++){
			cin >> arr[i][j];
		}
	}
	
	for(int i=1;i<=n;i++){
		cal_arr[i][0] = MIN(cal_arr[i-1][1],cal_arr[i-1][2]) + arr[i][0];
		cal_arr[i][1] = MIN(cal_arr[i-1][0],cal_arr[i-1][2]) + arr[i][1];
		cal_arr[i][2] = MIN(cal_arr[i-1][0],cal_arr[i-1][1]) + arr[i][2];
	}
	
	int min = cal_arr[n][0];
	if(min > cal_arr[n][1]) min = cal_arr[n][1];
	if(min > cal_arr[n][2]) min = cal_arr[n][2];
	
	cout << min << endl;
}
