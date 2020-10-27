#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;

int n,p;
int arr[300000];

void func(int &num){
	int tmp = 0;
	
	arr[num]++;
	
	while(num>0){
		tmp += pow(num%10, p);
		num /= 10;
	}
	
	num = tmp;
}

int main(){
	cin >> n >> p;
	
	int tmp = n;
	do{
		func(tmp);
		if(arr[tmp] > 2) break;
	}while(tmp != n);
	
	int cnt = 0;
	for(int i=0;i<300000;i++) {
		if(arr[i]==1) cnt++;
	}
	
	cout << cnt << endl;
}
