#include <iostream>
#include <algorithm>
using namespace std;

int arr[100000];
int brr[100000][2];
int answer;
int n;

int main(){
	cin >> n;
	for(int i=0;i<n;i++) cin >> arr[i];
	
	answer = arr[0];
	brr[0][0] = brr[0][1] = arr[0];
	
	for(int i=1;i<n;i++) {
		brr[i][0] = brr[i][1] = arr[i];
		
		brr[i][0] = max(brr[i-1][0]+arr[i], arr[i]);
		brr[i][1] = max(brr[i-1][0], brr[i-1][1] + arr[i]);
		
		answer = max({answer, brr[i][0], brr[i][1]});
	}
	
	cout << answer << endl;
}
