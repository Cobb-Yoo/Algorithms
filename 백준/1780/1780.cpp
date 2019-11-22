#include <iostream>
using namespace std;

int zero=0;
int one=0;
int maone=0;
int arr[2188][2188];

void func(int n, int a, int b){
	int num = arr[a][b];
	
	for(int i=a;i<a+n;i++){
		for(int j=b;j<b+n;j++){
			if(arr[i][j] != num){
				func(n/3,a,b);
				func(n/3,a+n/3,b);
				func(n/3,a+n*2/3,b);
				
				func(n/3,a,b+n/3);
				func(n/3,a,b+n*2/3);
				func(n/3,a+n/3,b+n/3);
				
				func(n/3,a+n*2/3,b+n/3);
				func(n/3,a+n/3,b+n*2/3);
				func(n/3,a+n*2/3,b+n*2/3);
				return;
			}
		}
	}
	
	if(num == -1) maone++;
	else if(num == 0) zero++;
	else if(num == 1) one++;
}

int main(){
	int n;
	cin >> n;
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin >> arr[i][j];
		}
	}
	
	func(n,0,0);
	
	cout << maone << endl;
	cout << zero << endl;
	cout << one << endl;
}
