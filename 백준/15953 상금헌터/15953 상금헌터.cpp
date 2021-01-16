#include <iostream>
using namespace std;

int arr[] = {0,5000000,3000000,2000000,500000,300000,100000};
int brr[] = {0,5120000,2560000,1280000,640000,320000};

int main(){
	int n; cin >> n;
	
	for(int i=0;i<n;i++){
		int a,b;
		cin >> a >> b;
		
		int answer = 0;
		if(a == 1) answer += arr[1];
		else if(1 < a && a <= 3) answer += arr[2];
		else if(3 < a && a <= 6) answer += arr[3];
		else if(6 < a && a <= 10) answer += arr[4];
		else if(10 < a && a <= 15) answer += arr[5];
		else if(15 < a && a <= 21) answer += arr[6];
		
		if(b == 1) answer += brr[1];
		else if(1 < b && b <= 3) answer += brr[2];
		else if(3 < b && b <= 7) answer += brr[3];
		else if(7 < b && b <= 15) answer += brr[4];
		else if(15 < b && b <= 31) answer += brr[5];
		
		cout << answer << endl;
	}
}
