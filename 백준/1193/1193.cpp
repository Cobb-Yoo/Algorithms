#include <iostream>
using namespace std;

void calcul(int n, int a){
	int b = 1;
	int result;
	if(a % 2 == 1){
		cout << (a-n+1)  << "/" << (b+n-1);
	}
	else{
		cout << (b+n-1) << "/" << (a-n+1);
	}
}

int main(){
	int n;
	int i;
	cin >> n;
	int cal;
	
	for(i=1;;i++){
		if(n <= i*(i+1)/2) break;
	}
	
	cal = i - i*(i+1)/2 + n;
	
	calcul(cal, i);
}
