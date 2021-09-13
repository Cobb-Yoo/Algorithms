#include<bits/stdc++.h>
using namespace std;

int main(){
	int n; cin >> n;
	int tmp = 10;
	
	while(n > tmp){
		n += tmp/2;
		n /= tmp;
		n *= tmp;
		
		tmp *= 10;
	}
	
	cout << n << endl;
}
