#include <bits/stdc++.h>
using namespace std;

int main(){
	int t; cin >> t;
	
	while(t--){
		int money; cin >> money;
		
		int quarter=0, dime=0, nicke=0, penny=0;
		
		quarter = money/25;
		money %= 25;
		
		dime = money/10;
		money %= 10;
		
		nicke = money/5;
		money %= 5;
		
		penny = money;
		
		cout << quarter << " " << dime << " " << nicke << " " << penny << endl;
	}
}
