#include <iostream>
#define MAX 1000000
using namespace std;

bool arr[MAX];

void init(){
	for(int i=2;i<=MAX;i++) arr[i] = true;
	
	for(int i=2;i*i<=MAX;i++){
		if(arr[i])
			for(int j=i*i;j<=MAX;j+=i)
				arr[j] = false;
	}
}

void cal(int n){
	int count=0;
	
	for(int i=n+1;i<=2*n;i++){
		if(arr[i]) count++;
	}
	
	cout << count << endl;
}

int main(){
	int n;
	
	init();
	
	while(cin >> n && n != 0){
		cal(n);
	}
}
