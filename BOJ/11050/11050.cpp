#include <iostream>
using namespace std;

int f(int n){
	int tmp=1;
	for(int i=1;i<=n;i++) tmp *= i;
	return tmp;
}

int combi(int a, int b){
	return f(a)/(f(a-b)*f(b));
}

int main(){
	int n, k;

	cin >> n >> k;
	
	cout << combi(n,k) << endl;
}
