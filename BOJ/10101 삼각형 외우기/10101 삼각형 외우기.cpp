#include <iostream>
using namespace std;

int main(){
	int a,b,c,sum=0;
	
	cin >> a >> b >> c;
	
	sum = a+b+c;
	
	if(sum == 180){
		if(a==b && a==c) cout << "Equilateral";
		else if(a==b || b==c || a==c) cout << "Isosceles";
		else cout << "Scalene";
	}
	else{
		cout << "Error";
	}
}
