#include <iostream>
#include <cmath>
using namespace std;

int arr_decimal[10000]={0};

void init(bool arr[]){
	for(int i=2;i<=10000;i++) arr[i] = true;
	
	for(int i=2;i*i<=10000;i++){
		if(arr[i]){
			for(int j=i*2;j<=10000;j+=i){
				arr[j] = false;
			}
		}
	}
	
	for(int i=1,j=0;i<=10000;i++){
		if(arr[i]) arr_decimal[j++] = i;
	}
}

bool cal(int n){
	int x = sqrt(n);
	for(int i=2;i<=x;i++){
		if(n%i==0) return false;
	}
	
	return true;
}

void cal_gold (int n){
	int temp1, temp2;
	int a,b;
	int min = 10000;
	for(int i=0;arr_decimal[i]<=n/2;i++){
		a = arr_decimal[i];
		b = n - a;
		
		if(!cal(b)) continue;
		
		if(min > b-a && b >= a){
				min = b-a;
				temp1 = a;
				temp2 = b;
		}
	}
	
	cout << temp1 << ' ' << temp2 << '\n';
}

int main(){
	int t;
	bool arr[10001];
	int n;
	cin >> t;
	
	init(arr);
	
	for(int i=0;i<t;i++){
		cin >> n;
		cal_gold(n);
	}
}
