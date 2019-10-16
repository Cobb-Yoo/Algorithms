#include <iostream>
#include <cmath>
using namespace std;

int cal(int x, int* min){
	int n = sqrt(x);
	
	if(x == 1) return 0;
	
	for(int i=2;i<=n;i++){
		if(x % i == 0) return 0;
	}
	
	if(*min > x) *min = x;
	return x;
}

int main(){
	int m,n;
	cin >> m;
	cin >> n;
	
	int sum=0;
	int min=10001;
	
	for(int i=m;i<n;i++){
		sum += cal(i,&min);
	}
	
	if(sum == 0){
		sum = -1;
		cout << sum;
	}
	else {
		cout << sum << endl << min;
	}
}
