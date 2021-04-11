#include <iostream>
using namespace std;

long long arr[1000][10001]={0};

void init(){
	for(int i=0;i<1000;i++){
		for(int j=0;j<10001;j++){
			arr[i][j] = 1;
		}
	}
}

void f(int a, int b){
	if(a == 0){
		cout << "0\n";
		return;
	}
	
	arr[1][0] = arr[1][1] = 1;
	
	for(int i=2;i<=a+1;i++){
		for(int j=1;j<i;j++){
			arr[i][j] = (arr[i-1][j-1] + arr[i-1][j])%10007;
		}
	}
	
	
	cout << arr[a][b] << endl;
}

int main(){
	int n,k;
	cin >> n >> k;
	
	init();
	f(n,k);
}
