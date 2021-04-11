#include <iostream>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

	int n;
	cin >> n;
	
	int arr[n+1]={0};
	int brr[n+1]={0};
	int tmp_A[n+1]={0};
	int tmp_B[n+1]={0};
	
	for(int i=1;i<=n;i++){
		cin >> arr[i];
		brr[n-i+1] = arr[i];
	}

	int MAX_A=0;
	int MAX_B=0;
	int MAX=0;
	
	
	for(int i=1;i<=n;i++){
		int max=0;
		for(int j=1;j<=i;j++){
			if(arr[i] > arr[j]){
				if(max < tmp_A[j])
					max = tmp_A[j];
			}
		}
		tmp_A[i] = max + 1;
		if(MAX_A < tmp_A[i]) MAX_A = tmp_A[i];
	}
		
	for(int i=1;i<=n;i++){
		int max=0;
		for(int j=1;j<=i;j++){
			if(brr[i] > brr[j]){
				if(max < tmp_B[j])
					max = tmp_B[j];
			}
		}
		tmp_B[i] = max + 1;
		if(MAX_B < tmp_B[i]) MAX_B = tmp_B[i];
	}
	
	for(int i=1;i<=n;i++)
		if(MAX < tmp_A[i] + tmp_B[n-i+1]) MAX = tmp_A[i] + tmp_B[n-i+1] - 1;
	
	cout << MAX << endl;
}
