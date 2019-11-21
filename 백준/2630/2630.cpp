#include <iostream>
using namespace std;

int arr[129][129];
int zero=0;
int one=0;

void cal(int n, int a, int b){
	int num = arr[a][b];
	
	for(int i=a;i<a+n;i++){
		for(int j=b;j<b+n;j++){
			if(arr[i][j] != num){
				cal(n/2,a,b);
				cal(n/2,a+n/2,b);
				cal(n/2,a,b+n/2);
				cal(n/2,a+n/2,b+n/2);
				return;
			}
		}
	}
	
	if(num == 1) one++;
	else zero++;
}

int main(){
	int n;
	cin >> n;
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin >> arr[i][j];
		}
	}
	
	cal(n,0,0);
	
	cout << zero << endl;
	cout << one << endl;
}
