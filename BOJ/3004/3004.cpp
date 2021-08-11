#include <bits/stdc++.h>
using namespace std;

int n;

int main(){
	cin >> n;
	
	if(n&1){
		cout << (n/2+1)*(n/2+2) << endl;
	}
	else {
		cout << (n/2+1)*(n/2+1) << endl;
	}
}
